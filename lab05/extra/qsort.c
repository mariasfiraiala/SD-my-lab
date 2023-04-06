#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "utils.h"

int comparator(const void *p, const void *q)
{
	struct route_table_entry route1 = *(struct route_table_entry *)p;
	struct route_table_entry route2 = *(struct route_table_entry *)q;

	if (route1.prefix == route2.prefix)
		return route2.mask - route1.mask;

	return route2.prefix - route1.prefix;
}

struct route_table_entry *dr_get_next_route(uint32_t ip_dest, struct route_table_entry *rtable, uint32_t rtable_len)
{
	qsort(rtable, rtable_len, sizeof(rtable[0]), comparator);

	for (uint32_t i = 0; i < rtable_len; ++i)
		if (rtable[i].prefix == (ip_dest & rtable[i].mask))
			return &rtable[i];

	return NULL;
}

int main(void)
{
	printf("Get back to work, looooser!\n");
	return 0;
}
