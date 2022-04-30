// Useful types for representing data

typedef struct DataPoint_t
{
    int item_id;
    int user_id;
    float rating;
} DataPoint_t;

DataPoint_t *DataPoint(int item_id, int user_id, float rating);
void DataPoint_print(DataPoint_t *dp);

typedef struct DataSet_t
{
    int n_items;
    int n_users;
    int n_ratings;
    DataPoint_t **data;
} DataSet_t;

DataSet_t *DataSet(int n_items, int n_users, int n_ratings, DataPoint_t **data);
void DataSet_print(DataSet_t *ds);
