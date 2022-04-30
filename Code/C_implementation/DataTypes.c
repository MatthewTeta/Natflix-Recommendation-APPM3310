#include <stdio.h>
#include "vec.h"
#include "DataTypes.h"

// DataPoint constructor
DataPoint_t *DataPoint(int item_id, int user_id, float rating)
{
    DataPoint_t *dp = malloc(sizeof(DataPoint_t));
    dp->item_id = item_id;
    dp->user_id = user_id;
    dp->rating = rating;
    return dp;
}

void DataPoint_print(DataPoint_t *dp)
{
    printf("DataPoint: item_id=%d\tuser_id=%d\trating=%f", dp->item_id, dp->user_id, dp->rating);
}

DataSet_t *DataSet(int n_items, int n_users, int n_ratings, DataPoint_t **data)
{
    DataSet_t *ds = malloc(sizeof(DataSet_t));
    ds->n_items = n_items;
    ds->n_users = n_users;
    ds->n_ratings = n_ratings;
    ds->data = data;
    return ds;
}

void DataSet_print(DataSet_t *ds)
{
    printf("DataSet: n_items=%d\tn_users=%d\tn_ratings=%d\n", ds->n_items, ds->n_users, ds->n_ratings);
}
