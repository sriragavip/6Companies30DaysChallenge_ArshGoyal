class DataStream {
public:
    int val,k,c=0;
    DataStream(int value, int k) {
        val=value;
        this->k=k;
    }
    bool consec(int num) {
        return ((num==val)?++c:c=0)>=k;
    }
};