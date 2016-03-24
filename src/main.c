/*
 * kenotaph-devlist - print all devices supported by libpcap.
 * Copyright (C) 2016  CodeWard.org
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pcap/pcap.h>

int
main (int argc, char *argv[])
{
	pcap_if_t *pcap_dev, *pcap_dev_iter;
	char errbuff[PCAP_ERRBUF_SIZE];

	if ( pcap_findalldevs (&pcap_dev, errbuff) == -1 ){
		fprintf (stderr, "%s: cannot obtain a list of devices: %s\n", argv[0], errbuff);
		return EXIT_FAILURE;
	}

	for ( pcap_dev_iter = pcap_dev; pcap_dev_iter != NULL; pcap_dev_iter = pcap_dev_iter->next ){
		if ( strcmp (pcap_dev_iter->name, "any") == 0 )
			continue;

		fprintf (stdout, "%s %s %s \"%s\"\n", pcap_dev_iter->name,
							((pcap_dev_iter->flags & PCAP_IF_UP)? "up":"down"),
							((pcap_dev_iter->flags & PCAP_IF_RUNNING)? "running":"stopped"),
							((pcap_dev_iter->description != NULL)? pcap_dev_iter->description:""));
	}

	pcap_freealldevs (pcap_dev);

	return EXIT_SUCCESS;
}

