#include <stdio.h>
#include <stdlib.h>
#include "league.h"

void print_league_nodes(team_node_ptr node_ptr)
{

	if (node_ptr -> left != NULL ) {
		/* must print left subtree first */
		print_league_nodes(node_ptr -> left);
	}
	/* now print out this node */
	printf("%-23s%4d   %4d%4d%4d%4d%4d   %4d%4d%4d%4d%4d   %4d\n",
		node_ptr -> name,
		node_ptr -> games_played,
		node_ptr -> home_wins,
		node_ptr -> home_draws,
		node_ptr -> home_losses,
		node_ptr -> home_goals_for,
		node_ptr -> home_goals_against,
		node_ptr -> away_wins,
		node_ptr -> away_draws,
		node_ptr -> away_losses,
		node_ptr -> away_goals_for,
		node_ptr -> away_goals_against,
		node_ptr -> points);
	if (node_ptr -> right != NULL ) {
		/* must print right subtree first */
		print_league_nodes(node_ptr -> right);
	}
}

void print_league_table(team_node_ptr tree_top_ptr, char * last_update)

{
	/* NOTE: in the below code, I need long strings, longer than will
		fit on one line, thus, I have used the ANSI feature
		that allows me to split a sx tring into two
		with the compiler arranging to concatenate parts together
		before it uses them.
	*/
	printf("Welsh Premier League table including results up to %s\n",
		last_update);
	printf("Team                                   Home"
		"                   Away\n");
	printf("Name                      P      W   D   L   F   A"
		"      W   D   L   F   A      P\n");

	print_league_nodes(tree_top_ptr);
}
