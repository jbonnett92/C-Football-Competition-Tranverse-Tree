/* This file defines structures used within the Football League program */

#define NUM_TEAMS 17

#define MAX_NAME_LENGTH 24

typedef struct team_status {
    char name[MAX_NAME_LENGTH];

    int games_played;

    int home_wins;
    int home_draws;
    int home_losses;
    int home_goals_for;
    int home_goals_against;

    int away_wins;
    int away_draws;
    int away_losses;
    int away_goals_for;
    int away_goals_against;

    int points;

    struct team_status * left; /* links to teams with more or same points */
    struct team_status * right; /* links to teams with less points */
    
} team_node;

typedef team_node * team_node_ptr;

#define LEAGUE_TABLE_FILE "league_table.data"

/* now the function prototype for the function that read and builds tree */

team_node_ptr get_league_table(char * league_table_filename,
	char * last_update);

/* now the function prototype for the functions that prints the league
	table from the tree
*/

void print_league_table(team_node_ptr tree_top_ptr, char * last_update);

/* Now the function prototypes for the generic tree walking
	function and the two node action functions
*/

void traverse_league_nodes(team_node_ptr node_ptr,
	void (* action)(team_node_ptr) );
void print_a_node(team_node_ptr node_ptr);
void print_home_away(team_node_ptr node_ptr);
