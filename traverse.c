#include <stdio.h>
#include <stdlib.h>
#include "league.h"

/* Note the first parameter to this function points at a tree node,
	the second parameter is a pointer to a function,
	which takes a tree node pointer as its argument
	but itself retuirns a void
*/
void traverse_league_nodes(team_node_ptr node_ptr,
	void (* action)(team_node_ptr) )
{

	if (node_ptr -> left != NULL ) {

		/* must deal with left subtree first */

		traverse_league_nodes(node_ptr -> left, action);
	}

	/* now invoke the action function do do whatever
		it does on this node
	*/

	action(node_ptr);

	if (node_ptr -> right != NULL ) {
		/* must deal with right subtree first */
		traverse_league_nodes(node_ptr -> right, action);
	}
}




void print_a_node(team_node_ptr node_ptr)
{
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
}

void print_home_away(team_node_ptr node_ptr)
{
	int home_points, away_points;

	/* calculate points based on 3 points for a win and 1 for a draw */

	home_points = node_ptr -> home_wins * 3 + node_ptr -> home_draws;
	away_points = node_ptr -> away_wins * 3 + node_ptr -> away_draws;

	/* now print out name and home and away points for this node */

	printf("%-23s scored %d points at home and %d points away\n",
		node_ptr -> name, home_points, away_points);
}
