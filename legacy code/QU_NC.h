
#include <vector>
class QU_NC {
private:
    std::vector<int> root;
public:
    void init(int n);

    int Find(int x);

    void Union(int x, int y);
};


class UR_NC {
private:
    std::vector<int> P;
    int nr_blocks;
public:
    void init(int n);

    int Find(int x);

    void Union(int x, int y);

    void PrintFullData();
};
