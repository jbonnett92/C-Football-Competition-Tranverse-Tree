#include <stdio.h>
#include <stdlib.h>
#include "league.h"

int main ()
{
	char last_updated_on[11]; /* this is used to hold date of last update */
	team_node_ptr tree_top;   /* used to point at the top of the tree */

	/* read in the league table  data and populate the tree */

	tree_top = get_league_table(LEAGUE_TABLE_FILE,last_updated_on);

	/* report when the table was last updated  and which tem
		is at the top of the tree so we can check
		that the program has read the data correctly */

	printf("======DEBUGING printout so we can check all is o.k.======\n");

	printf("League table last updated on %s\n", last_updated_on);

	printf("team at top of tree is %s who have %d points from %d games\n",
		tree_top -> name, tree_top -> points, tree_top -> games_played);

	printf("================END of DEBUGING printout ================\n");
	printf("\n\n\n\n");


	/* Now printout the league table using our printing function */

	print_league_table(tree_top, last_updated_on);

	/* now use the generic tree walking function giving
		it a pointer to a different node action
		function each time we call it
	*/

	printf("========================================================\n");


	printf("team data using tree traversing function\n");

	traverse_league_nodes(tree_top, &print_a_node);

	printf("home and away points using tree traversing function\n");

	traverse_league_nodes(tree_top, &print_home_away);
}
