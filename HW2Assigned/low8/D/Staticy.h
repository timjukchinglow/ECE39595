
class Staticy {
public:
    static Staticy* makeStaticy(int i);
    static int getEvenCount();
private:
    static int EvenCount;
    Staticy(int i);
};

