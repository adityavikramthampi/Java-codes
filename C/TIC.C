#include<stdio.h>
#include<stdlib.h>

int board[9], turn=1, i, j, k, m, a[3], pos;

int row(int c) {

    for(j = 0; j < 7; j+=3) { // repeat for row

			m=0;

			for(k = j; k < j+3; k++) { //row

				a[m++] = board[k];

				if (board[k] == 2)
					pos = k;
			}

			if(a[0]*a[1]*a[2] == c)
				return pos;

		}
	return -1;
}

int column(int c) {

    for(j = 0; j < 3; j++) { //repeat for column

			m=0;

			for(k = j; k <= j+6; k+=3) { //column

				a[m++] = board[k];

				if (board[k] == 2)
					pos = k;
			}

			if(a[0]*a[1]*a[2] == c)
				return pos;

		}
	return -1;
}

int diag1(int c) {

    if(board[0]*board[4]*board[8] == c) { //diagonal

			if(board[0] == 2)
				return 0;

			if(board[4] == 2)
				return 4;

			if(board[8] == 2)
				return 8;

      return 1;  
		}
    return -1;
}

int diag2(int c) {

    if(board[2]*board[4]*board[6] == c) { //diagonal

			if(board[2] == 2)
				return 2;

			if(board[4] == 2)
				return 4;

			if(board[6] == 2)
				return 6;

      return 1;
		}
    return -1;
}

void display(int d) {
    if(d == 2)
        printf("_ ");
    else
        if(d == 3)
            printf("X ");
        else
            printf("O ");
}

int make2() {

	if(board[4] == 2)
		return 4;

	for(i = 1; i < 8; i+=2)	{

		if(board[i] == 2)
			return i;
	}

	for(i = 0; i <= 8; i+=2) {

		if(board[i] == 2)
			return i;
	}

}

int possWin() {

	if ((turn%2) != 0) {

		if(row(18) != -1)
		    return row(18);

		if(column(18) != -1)
		    return column(18);

        if(diag1(18) != -1)
		    return diag1(18);

		if(diag2(18) != -1)
		    return diag2(18);

        if(column(50) != -1)
		    return column(50);

		if(row(50) != -1)
		    return row(50);

		if(diag1(50) != -1)
		    return diag1(50);

		if(diag2(50) != -1)
		    return diag2(50);

	}

	else {

	    if(row(50) != -1)
		    return row(50);

		if(column(50) != -1)
		    return column(50);

		if(diag1(50) != -1)
		    return diag1(50);

		if(diag2(50) != -1)
		    return diag2(50);

		if(row(18) != -1)
		    return row(18);

		if(column(18) != -1)
		    return column(18);

		if(diag1(18) != -1)
		    return diag1(18);

		if(diag2(18) != -1)
		    return diag2(18);

	}

	return -1;
}

int go() {

	if ((turn%2) != 0) { // chance of X

		++turn;
		return 3;
	}

	else { // chance of O

		++turn;
		return 5;
	}
}

void main() {

	for(i=0; i<9; i++)
		board[i] = 2;

	for(i=0; i<9; i+=3) {

            display(board[i]);
            display(board[i+1]);
            display(board[i+2]);
            printf("\n");
		}

	while(1) {

		printf("Enter a pos: ");
		scanf("%d",&pos);

		board[--pos] = go();

		for(i=0; i<9; i+=3) {

            display(board[i]);
            display(board[i+1]);
            display(board[i+2]);
            printf("\n");
		}

		if(possWin() == -1)
			board[make2()] = go();

		else
			board[possWin()] = go();

		printf("\n");

		for(i=0; i<9; i+=3) {

            display(board[i]);
            display(board[i+1]);
            display(board[i+2]);
            printf("\n");
		}

		if((row(27) != -1) || (row(125) !=-1)) {
		    printf("Game over!");
			return;
		}

		if((column(27) != -1) || (column(125) !=-1)) {
		    printf("Game over!");
			return;
		}

		if((diag1(27) != -1) || (diag1(125) !=-1)) {
		    printf("Game over!");
			return;
		}

		if((diag2(27) != -1) || (diag2(125) !=-1)) {
		    printf("Game over!");
			return;
		}


		if(board[0]!=2 && board[1]!=2 && board[2]!=2 && board[3]!=2 && board[4]!=2 && board[5]!=2 && board[6]!=2 && board[7]!=2 && board[8]!=2) {
			printf("Game over!");
			break;
		}
	}
}
