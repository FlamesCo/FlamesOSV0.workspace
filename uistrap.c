void agi(int x, int y, int ch, int fg, int bg) {
	char cell[2] = {ch, '\0'};
	if(bg != -1) {
		cell[1] = '\x1b';
		cell[2] = '[';
		cell[3] = '4';
		cell[4] = bg + '0';
		cell[5] = 'm';
		cell[6] = '\0';
	}
	if(fg != -1) {
		cell[1] = '\x1b';
		cell[2] = '[';
		cell[3] = '3';
		cell[4] = fg + '0';
	    cell[5] = 'm'; 
        cell[6] = '\0'; 

    }   
    printf("%s", cell); 

    if(x >= 0 && y >= 0) { 

     printf("\x1b[%d;%dH", y + 1, x + 1); 

    }   

   }  

 END AGI: 

 void end_agi() { 

    agi(-1, -1, 0, -1, -1); 

 }
