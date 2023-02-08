//
// Created by benrr on 2/2/2023.
//

#include "Move.h"
#include "Board.h"

string colLetter(int col)
{
    if (col == 7){ return"a";}
    else if (col == 6){ return"b";}
    else if (col == 5){ return"c";}
    else if (col == 4){ return"d";}
    else if (col == 3){ return"e";}
    else if (col == 2){ return"f";}
    else if (col == 1){ return"g";}
    else { return"h";}
}

Move::Move(int sq1, int sq2, int piece, int take)
{
    initial = sq1 * piece;
    final = sq2 * take;
}

int Move::getInitial()
{
    return initial;
}

int Move::getFinal()
{
    return final;
}

int Move::getInitialRow() {
    if (initial % 67 == 0) { return initial / 67; }
    else if (initial % 71 == 0) { return initial / 71; }
    else if (initial % 73 == 0) { return initial / 73; }
    else if (initial % 79 == 0) { return initial / 79; }
    else if (initial % 83 == 0) { return initial / 83; }
    else if (initial % 89 == 0) { return initial / 89; }
    else { return initial / 97; }
}

int Move::getFinalRow()
{
    if (final % 67 == 0) { return final / 67; }
    else if (final % 71 == 0) { return final / 71; }
    else if (final % 73 == 0) { return final / 73; }
    else if (final % 79 == 0) { return final / 79; }
    else if (final % 83 == 0) { return final / 83; }
    else if (final % 89 == 0) { return final / 89; }
    else { return final / 97; }
}

int Move::getInitialCol()
{
    if (initial % 67 == 0) { return initial % 67; }
    else if (initial % 71 == 0) { return initial % 71; }
    else if (initial % 73 == 0) { return initial % 73; }
    else if (initial % 79 == 0) { return initial % 79; }
    else if (initial % 83 == 0) { return initial % 83; }
    else if (initial % 89 == 0) { return initial % 89; }
    else { return initial % 97; }
}

int Move::getFinalCol()
{
    if (final % 67 == 0) { return final % 67; }
    else if (final % 71 == 0) { return final % 71; }
    else if (final % 73 == 0) { return final % 73; }
    else if (final % 79 == 0) { return final % 79; }
    else if (final % 83 == 0) { return final % 83; }
    else if (final % 89 == 0) { return final % 89; }
    else { return final % 97; }
}

/** string Move::printMove(int piece, int capture)
{
    string res;

    if (piece == 1) {
        if (final_col != initial_col) {
            res += colLetter(initial_col);
            res += "x";
            res += colLetter(final_col);
            res += to_string(final_row + 1);
        }
        else {
            res += colLetter(initial_col);
            res += to_string(final_row + 1);
        }
        return res;
    }

    else if (piece == 2)
    {
        res += "N";
        if (capture != 0)
        {
            res += "x";
        }
        res += colLetter(final_col);
        res += to_string(final_row + 1);
        return res;
    }

    else if (piece == 3)
    {
        res += "B";
        if (capture != 0)
        {
            res += "x";
        }
        res += colLetter(final_col);
        res += to_string(final_row + 1);
        return res;
    }

    else if (piece == 4)
    {
        res += "R";
        if (capture != 0)
        {
            res += "x";
        }
        res += colLetter(final_col);
        res += to_string(final_row + 1);
        return res;
    }

    else if (piece == 5)
    {
        res += "Q";
        if (capture != 0)
        {
            res += "x";
        }
        res += colLetter(final_col);
        res += to_string(final_row + 1);
        return res;
    }

    else if (piece == 6)
    {
        if (abs(initial_col - final_col) != 1)
        {
            if (abs(initial_col - final_col) == 2)
            {
                return "O-O";
            }
            else
            {
                return "O-O-O";
            }
        }
        res += "K";
        if (capture != 0)
        {
            res += "x";
        }
        res += colLetter(final_col);
        res += to_string(final_row + 1);
        return res;
    }

    return res;
}
**/

