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

Move::Move(int row1, int col1, int row2, int col2)
{
    initial_row = row1;
    initial_col = col1;
    final_row = row2;
    final_col = col2;
}

int Move::getInitialRow()
{
    return initial_row;
}

int Move::getFinalRow()
{
    return final_row;
}

int Move::getInitialCol()
{
    return initial_col;
}

int Move::getFinalCol()
{
    return final_col;
}

string Move::printMove(int piece, int capture)
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

