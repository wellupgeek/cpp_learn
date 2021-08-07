
class MonsterDB{
private:
    ~MonsterDB(){}
public:
    static void DestroyInstance(MonsterDB* pb) {
        delete pb;
    }
    void dosomething(){}
};

int main() {
    MonsterDB* pb = new MonsterDB();
    pb->dosomething();
    MonsterDB::DestroyInstance(pb);
    return 0;
}