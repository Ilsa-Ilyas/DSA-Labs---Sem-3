#include <iostream>
using namespace std;

class TreasureHunt {
	char cave[6][6];
	bool visited[6][6];
	int MinEnergyLoss;
	
	private:
		void backtrack (int rows, int columns, int energylost) {
			//boundary
			if (r<0 || c<0 || r>6 || c>6) {
				return;
			}
			//dangerous or visited must be skipped
			if(cave[r][c]='D' || visited[r][c]) {
				return;
			}
			//reached treasure
			if(cave[r][c]='T'){
				if(energylost < MinEnergyLost) {
					MinEnergyLost = energylost;
					return;
				}
			//visited marked
			visited[r][c] = true;
			
			//hazardous loose energy
			if(cave[r][c]='H'){
				energylost++;	
			}
			
			//directions
			backtrack(r+1, c, energylost); //down
			backtrack(r, c+1, energylost); //right
			backtrack(r-1, c, energylost); //up
			backtrack(r, c-1, energylost); //left
			
			//unmark
			visited[r][c]=false;
			}
		}
	
	public:
		TreasureHunt(char grid[6][6]){
			for (int i=0; i<6; i++){
				for (int j=0; j<6;j++){
					cave[i][j] = grid[6][6];
					visited[i][j] = false;
				}
			}
			MinEnergyLoss = 1000; //large value
		}
		
		void findtrasure(){
			backtrack (0,0,0);
			if (MinEnergyLoss == 1000) {
				cout << "No path" << endl;
			}
			else {
				cout << "Min energy loss: " << MinEnergyLost << endl;
			}
		}
};

int main () {
	    char grid[6][6] = {
        {'S','P','P','D','H','H'},
        {'P','P','P','D','P','H'},
        {'P','H','P','P','P','D'},
        {'P','D','P','D','P','P'},
        {'P','P','P','H','P','D'},
        {'P','D','P','P','P','T'}
    };
    
    TreasureHunt game(grid);
    game.findtrasure();
    
    return 0;
}