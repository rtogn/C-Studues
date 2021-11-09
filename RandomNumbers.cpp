#include <iostream>
#include <random>
#include <ctime>

namespace random_rolls {

    std::random_device rd;
    std::mt19937 rng(time(0) + (rd() | rd())); // memes
    //std::mt19937 rng( rd()); GCC DOES NOT IMPLEMENT RD CORRECTLY. USE THIS IF I GET AN UPDATED COMPILER :V

    int RandInt(int low, int high) {
    std::uniform_int_distribution<int> distribution(low, high);
    return distribution(rng);
}
} // namespace random_rolls

namespace random_weighted_tables {

    using random_rolls::RandInt;
    const int WEIGHT = 0;
    const int VALUE = 1;

    int LookupWeightedTableVal (int table[][2], int table_length, int roll) {

        int cumulative_weight = 0;

        for (int i = 0; i < table_length; i++) {
            cumulative_weight += table[i][WEIGHT];
            if (roll <= cumulative_weight) {
                return table[i][VALUE];
            }
        }
        return '*';
    }

    int RollWeightedTable (int table[][2], int table_length) {
        /* X must be between 0 & the sum of weights in listed table.
        *  Calculates sum of values in table and rolls in that range.
        *  Fast version will have to take optional pre-calculated sum.
        * Width of array must be 2 in the form {WEIGHT, VALUE}.
        * Thanks: https://www.redblobgames.com/articles/probability/damage-rolls.html
        */
        int sum_of_weights = 0;

        for (int i = 0; i < table_length; i++) {
            sum_of_weights += table[i][WEIGHT];
        }
        int rollWeight = RandInt(1, sum_of_weights);
        return LookupWeightedTableVal(table, table_length, rollWeight);
    }

    int PreCalculateTableWeight (int table[][2], int table_length) {
        // Precalculate total table weight so each roll doesn't have to re-calc.
        // lmao this saved no discernible time but i feel better about it.
        int weightSum = 0;

        for (int i = 0; i < table_length; i++) {
            weightSum += table[i][WEIGHT];
        }
        return weightSum;
    }

    int RollPreCalcWeightedTable (int table[][2], int table_length, int weight_sum) {
        // Requires pre calculated sum of table weights. Use dynamic version for
        // smaller, varied tables.
        int cumulative_weight = 0;

        int roll = RandInt(1, weight_sum);

        for (int i = 0; i < table_length; i++) {
            cumulative_weight += table[i][WEIGHT];
            if (roll <= cumulative_weight) {
                return table[i][VALUE];
            }
        }
        return '*';
    }
} // namespace random_weighted_tables


   //class RR {
//    public:
//        static int randInt(int low, int high) {
//            std::uniform_int_distribution<int> distribution(low, high);
//            return distribution(rng);
//        }
//};


