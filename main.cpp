#include <iostream>
#include <vector>
#include <algorithm>
#include <cfloat>


void search(float cost[10][10], std::vector<int> available, float current_cost,float &max, int current){
    if(current == 9) {
        max = std::min(current_cost, max); 
    }else{
        for(int i = 0; i < available.size(); i++){
            if(cost[current][available[i]] != -1.0) {
                std::vector<int> new_available (available);
                new_available.erase(new_available.begin() + i);
                search(cost, new_available, current_cost+ cost[current][available[i]], max, available[i]);
            }
        }
    }
}


int main(){
    
    //pobranie parametrów kosztu
    unsigned int red, green, yellow;
    std::cout << "Podaj koszt przejazdu metra drogi zielonej: ";
    std::cin >> green;
    std::cout << "Podaj koszt przejazdu metra drogi żółtej: ";
    std::cin >> yellow;
    std::cout << "Podaj koszt przejazdu metra drogi czerownej: ";
    std::cin >> red;

    float cost[10][10]; //stworzenie tablicy połączeń między punktami
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cost[i][j] = -1.0;
        }
    }

    //wczytanie wartości do tablicy kosztów z przeliczeniem na jednostki energii
    cost[0][1] = 7.2 * green;
    cost[0][3] = 3.3 * red;
    cost[0][4] = 12.3 * yellow;

    cost[1][0] = cost[0][1];
    cost[1][2] = 1.7 * yellow;
    cost[1][7] = 7.8 * red;
    
    cost[2][1] = cost[1][2];
    cost[2][3] = 3.7 * green;
    cost[2][6] = 4.2 * yellow;

    cost[3][0] = cost[0][3];
    cost[3][2] = cost[2][3];
    cost[3][4] = 1.3 * red;

    cost[4][0] = cost[0][4];
    cost[4][3] = cost[3][4];
    cost[4][5] = 2.0 * red;

    cost[5][4] = cost[4][5];
    cost[5][6] = 3.5 * green;
    cost[5][8] = 6.8 * red;
    
    cost[6][2] = cost[2][6];
    cost[6][5] = cost[5][6];
    cost[6][7] = 4.5 * green;
    cost[6][8] = 7.5 * yellow;

    cost[7][1] = cost[1][7];
    cost[7][6] = cost[6][7];
    cost[7][9] = 10 * green;

    cost[8][5] = cost[5][8];
    cost[8][6] = cost[6][8];
    cost[8][9] = 2 * yellow;

    //stworzenie zbioru wszystkich mozliwych punktów
    std::vector<int> available = {1, 2, 3, 4 ,5 ,6 ,7, 8, 9};
    float max = FLT_MAX; //ustalenie bazowej odległości maksymalnej
    search(cost,available, 0, max, 0); //wywołanie funkcji szukającej
    std:: cout << max << std::endl;

}