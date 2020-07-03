#ifndef RentalCar_h
#define RentalCar_h

class RentalCar {
    public:
        RentalCar ();
        RentalCar (int y, char *mk, char *md, float p, bool a);
        void printCar ();
        float carEstimate (int days);
        void setYear(int y);
        void setMake(char *mk);
        void setModel(char *md);
        void setPrice(float p);
        void setAvailable(bool a);
        const int getYear() const;
        const char *getMake() const;
        const char *getModel() const;
        const float getPrice() const;
        const bool getAvailable() const;
        
    private:
        int m_year;
        char m_make[256];
        char m_model[256];
        float m_price;
        bool m_available;
};

char *myStringCopy (char *destination, const char *source);

#endif