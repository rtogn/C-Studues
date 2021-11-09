#include <iostream>
#include <string>
#include "RandomNumbers.h"

namespace  NASDAQ_symbol_generation {
    // Come back later and refactor names. having NASDAQ in front of all of them is hard to read
    using std::string;
    using random_rolls::RandInt;
    int NASDAQ_symbol_length_weights[4][2] = {
    // Table of weights for % occurence of ticker symbol lengths of 2-5 (excluded zillow as the only with 1 character)
    // Format {weight, lengthValue}
        {20,5},
        {71, 4},
        {8, 3},
        {2,2}
    }; // NASDAQ_Symbol_length_weights
    int NASDAQ_len_size = sizeof(NASDAQ_symbol_length_weights) / sizeof(NASDAQ_symbol_length_weights[0]);

    int NASDAQ_char_weights[26][2] = {
    // Table of weights and associated character for occurrence of stock ticker letters in NASDAQ
    // They are out of alph order. It can be fixed if gotten around to.
    // Only convenient because char maps nice to int.
        {81, 'C'},{75,'A'},{64,'S'},{61, 'T'},
        {59, 'R'},{56, 'N'},{52, 'I'},{48, 'L'},
        {46, 'P'},{44, 'B'},{43, 'M'},{43, 'O'},
        {42, 'E'},{33, 'G'},{32, 'W'},{31, 'U'},
        {29, 'D'},{29, 'F'},{29, 'H'},{25, 'V'},
        {24, 'X'},{20, 'K'},{16, 'Y'},{8, 'Z'},
        {6, 'Q'},{4, 'J'}
    }; // end NASDAQ_char_weights
    int NASDAQ_table_size = sizeof(NASDAQ_char_weights) / sizeof(NASDAQ_char_weights[0]);
    int NASDAQ_table_weight = random_weighted_tables::PreCalculateTableWeight(NASDAQ_char_weights, NASDAQ_table_size);

    string GenernateSymbol(int symbolCount) {

        int symbol_length = RandInt(2,5);

        char symbol[symbol_length +1];
        for (int i = 0; i < symbol_length; i++) {
            symbol[i] = (char)RandInt(65, 90);
        }
        symbol[symbol_length] = '\0';
        return symbol;
    }

    int GenWeightedSymbolLength() {
        // Generates a symbol length based on weights calculated from nasdaq symbol list in table above.
        return random_weighted_tables::RollWeightedTable(NASDAQ_symbol_length_weights, NASDAQ_len_size);
    }
    string GenWeightedSymbol() {
    // Generates a symbol of length from GenWeightedSymbolLength() and with chars based on rate of occurrence from table above.
        int symbol_length = GenWeightedSymbolLength();
        char symbol[symbol_length +1];

        for (int i = 0; i < symbol_length; i++) {
            symbol[i] = random_weighted_tables::RollPreCalcWeightedTable(NASDAQ_char_weights, NASDAQ_table_size, NASDAQ_table_weight);
            //(char)RandInt(65, 90);
        }
        //Add escape character to last entry because C.
        symbol[symbol_length] = '\0';
        return symbol;
    }


    int sector_weights[12][2] = {
    /* Table of weights for % occurence of ticker symbol lengths of 2-5 (excluded zillow as the only with 1 character)
     Format {weight, lengthValue}
        Number map:
            1	Finance	1028	28.26%
            2	Health Care	934	25.67%
            3	Technology	507	13.94%
            4	Consumer Services	383	10.53%
            5	Capital Goods	206	5.66%
            6	Consumer Non-Durables	113	3.11%
            7	Miscellaneous	110	3.02%
            8	Consumer Durables	93	2.56%
            9	Basic Industries	84	2.31%
            10	Energy	63	1.73%
            11	Public Utilities	62	1.70%
            12	Transportation	55	1.51%
    */
        {1028,1},{934, 2},{507, 3},{383,4},
        {206,5},{113,6},{110,7},{93,8},
        {84,9},{63,10},{62,11},{55,12}
    }; // NASDAQ_Symbol_length_weights
    int sector_weight_size = sizeof(sector_weights) / sizeof(sector_weights[0]);

    string GetSector() {

        int result = random_weighted_tables::RollWeightedTable(sector_weights, sector_weight_size);

        string sectors[] = {
        "Finance", "Health Care", "Technology", "Consumer Services",
        "Capital Goods","Consumer Non-Durables", "Miscellaneous","Consumer Durables",
        "Basic Industries","Energy", "Public Utilities","Transportation"
        };
        return sectors[result-1];
    }
} // namespace  NASDAQ_symbol_generation
