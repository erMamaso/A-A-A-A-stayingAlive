#include "hashTable.hh"



hashTable::hashTable(int size){
    this->size = size;
    std::pair <double,int> aux(-1,-1);
    this->table = std::vector< std::pair <double,int>>(size,aux);

}

int hashTable::formkey (int elem){
    double n, ir = 1+pow(5,0.5)/2;
    ir = ir*elem;
    double fractir = std::modf(ir,&n);
    for(int i=0;i<5;i++){
      fractir*=10;
    }
    return floor(size*fractir);
}

clock_t hashTable::addElement(int key, int elem){
    clock_t t;
    t = clock();
    int hash = key%size;
    while(table[hash].first != -1 && table[hash].first != key){
            hash = (hash+1) % size;
    }
    table[hash].first = key;
    table[hash].second = elem;
    t = clock() - t;
    return t;
}

int hashTable::findElement(int key){
    int hash = key%size;
    for(int x=0;x<table.size();x++){
        if(table[hash].first != -1 && table[hash].first == key){
                return table[hash].second;
        }
        hash = (hash+1)%size;
    }
    return -1;
}

void hashTable::out(){

    for(int i=0;i<table.size();i++){
        std::cout << table[i].first << "/" << table[i].second << " ";
    }
    std::cout << std::endl;

}
