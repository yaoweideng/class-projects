#ifndef Agency_h
#define Agency_h

class Agency {
    public:
        Agency();
        char *getName();
        int getZipCode();
        void setName(char *n);
        void setZipCode(int zc);
        Car &operator[](const int index);
        void readAllData(ifstream &inputFile);
        void printAllData();
        void printAvailableCars();
    private:
        char m_name[256];
        int m_zipcode;
        Car m_inventory[5];
};

#endif