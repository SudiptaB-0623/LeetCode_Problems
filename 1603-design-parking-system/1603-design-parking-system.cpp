class ParkingSystem 
{
public:
    
    int bigLimit, mediumLimit, smallLimit;

    int *parkingArray;

    ParkingSystem(int big, int medium, int small) 
    {
        
        this->bigLimit = big;
        this->mediumLimit = medium;
        this->smallLimit = small;
        this->parkingArray = (int*)malloc((big + medium + small) * sizeof(int));
        for(int i = 0; i < big + medium + small; i++) 
        {
            this->parkingArray[i] = -1;
        }
    }

    bool addCar(int carType) 
    {
        int lim = 0;
        if(carType == 1) 
        {
            lim = this->bigLimit;
        } 
        else if(carType == 2) 
        {
            lim = this->mediumLimit;
        } 
        else 
        {
            lim = this->smallLimit;
        }
        int cnt = 0;
        for(int i = 0; i < this->bigLimit + this->mediumLimit + this->smallLimit; i++) 
        {
            if(this->parkingArray[i] == carType) 
            {
                cnt++;
            }
            if(cnt == lim) 
            {
                return false;
            }
            if(this->parkingArray[i] == -1) 
            {
                this->parkingArray[i] = carType;
                return true;
            }
        }
        return false;
    }
};