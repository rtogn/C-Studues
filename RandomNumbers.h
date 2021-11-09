
namespace random_rolls {

    int RandInt(int low, int high);
} // namespace Random
namespace random_weighted_tables {

    int RollWeightedTable (int table[][2], int table_length);
    int LookupWeightedTableVal (int table[][2], int table_length, int roll);
    int PreCalculateTableWeight (int table[][2], int table_length) ;
    int RollPreCalcWeightedTable (int table[][2], int table_length, int weight_sum) ;
} // namespace WeightedTables
