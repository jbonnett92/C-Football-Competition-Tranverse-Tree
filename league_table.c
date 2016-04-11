#include <stdio.h>
#include <stdlib.h>
#include "league.h"

team_node_ptr read_team_node(FILE * league_table_file)
{
	int scan_status;

	team_node * temp_team_node;

	/* Dynamically request memory for one node*/

	temp_team_node = calloc(1, sizeof(team_node));


	scan_status = fscanf(league_table_file, "%s%d%d%d%d%d%d%d%d%d%d%d%d",
		temp_team_node -> name,
		& temp_team_node -> games_played,
		& temp_team_node -> home_wins,
		& temp_team_node -> home_draws,
		& temp_team_node -> home_losses,
		& temp_team_node -> home_goals_for,
		& temp_team_node -> home_goals_against,
		& temp_team_node -> away_wins,
		& temp_team_node -> away_draws,
		& temp_team_node -> away_losses,
		& temp_team_node -> away_goals_for,
		& temp_team_node -> away_goals_against,
		& temp_team_node -> points);
	if (scan_status == EOF) {
		printf("Problem reading league table entry\n");
		return NULL;
	} else {
		printf("Read league table entry for %s who have %d points\n",
			temp_team_node -> name,
			temp_team_node -> points);
		return temp_team_node;
	}
}


void add_team_node(team_node_ptr current, team_node_ptr new)
{
	if (new -> points < current -> points) {
		/* we need to add new node on right subtree as
		   it has less points than current node */
		if (current -> right == NULL) {
			/* right link currently null so add directly */
			current -> right = new;
			printf("Just added %s to right link of %s\n",
				new -> name, current -> name );
		} else {
			/* must add further down subtree so recurse */
			add_team_node(current -> right, new);
		}
	} else {
		/* we need to add new node on left subtree as
		   it has more or same points as current node */
		if (current -> left == NULL) {
			/* left link currently null so add directly */
			current -> left = new;
			printf("Just added %s to left link of %s\n",
				new -> name, current -> name );
		} else {
			/* must add further down subtree so recurse */
			add_team_node(current -> left, new);
		}
	}

}


team_node_ptr get_league_table(char * league_table_filename,
	char * last_update)
{
    int team;

    FILE * league_table_file;

    team_node_ptr tree_top_ptr;
    team_node_ptr temp_node_ptr;

    league_table_file = fopen(league_table_filename, "r");

    if (league_table_file != NULL) {

        fscanf(league_table_file, "%s", last_update);

	/* Get the first team status information
		from the file and put it at the top
		of the tree
	*/

	tree_top_ptr = read_team_node(league_table_file);

	/* for for the rest of the teams, get the data
		from the file and add them into the tree
	*/

        for (team = 1 ; team < NUM_TEAMS; team++) {
		temp_node_ptr = read_team_node(league_table_file);

		/* and now add the new node into the tree */
		add_team_node(tree_top_ptr, temp_node_ptr);
        }
    } else {
        printf("Failed to open league table file\n");
        return NULL;
    }
    fclose(league_table_file);
    return tree_top_ptr;
}
