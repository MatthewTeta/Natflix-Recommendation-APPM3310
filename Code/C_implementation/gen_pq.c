#include <stdio.h>
#include "vec.h"
#include "DataTypes.h"

void printHelp(char *argv[])
{
    printf("Usage:\t%s input_filepath\n", argv[0]);
}

int line_has_colon(char *line)
{
    char *c = line;
    int rv = 0;
    while (*c != '\0')
    {
        if (*c == ':')
        {
            rv = 1;
            break;
        }
        c++;
    }
    return rv;
}

// Load data in from input files, return a DataSet *
int load_data(char *filepath, DataSet_t **dataset)
{
    int rv = 0;

    char line[32];
    int item_id = -1;
    int max_item_id = 0;
    int max_user_id = 0;
    int n_ratings = 0;
    FILE *input_file = fopen(filepath, "r");
    if (input_file == NULL)
    {
        rv = -3;
    }
    else
    {
        // Read lines from the file
        int user_id;
        float rating;
        DataPoint_t **ratings = vector_create();
        while (fgets(line, 32, input_file) != NULL)
        {

            if (line_has_colon(line))
            {
                // Interpret line as a new item_id
                if (sscanf(line, "%d", &item_id) != 1)
                {
                    rv = -1;
                    break;
                }
                else
                {
                    if (item_id > max_item_id)
                    {
                        max_item_id = item_id;
                    }
                }
            }
            else
            {
                // Interpret line as a DataPoint
                if (sscanf(line, "%d,%f", &user_id, &rating) != 2)
                {
                    rv = -2;
                    break;
                }
                else
                {
                    // Create new DataPoint instance and append to vector
                    DataPoint_t *dp = DataPoint(item_id, user_id, rating);
                    vector_add(&ratings, dp);
                    n_ratings++;
                    // Determine number of users and items
                    if (user_id > max_user_id)
                    {
                        max_user_id = user_id;
                    }
                }
            }
        }

        // Create a DataSet instance to group the data and assign to function argument pointer dataset
        *dataset = DataSet(max_item_id, max_user_id, n_ratings, ratings);
    }

    return rv;
}

int gen_pq(char *filepath)
{
    int rv = 0;
    // Load data
    DataSet_t *RatingSet = DataSet(0, 0, 0, NULL);
    if ((rv = load_data(filepath, &RatingSet)) == 0)
    {
        // Do backprop
        DataSet_print(RatingSet);
    }

    return rv;
}

int main(int argc, char *argv[])
{
    int rv = 0;

    // Parse options
    if (argc < 2)
    {
        printHelp(argv);
        rv = 1;
    }
    else
    {
        char *filepath = argv[argc - 1];
        rv = gen_pq(filepath);
    }

    // Don't forget to free memory

    return rv;
}
