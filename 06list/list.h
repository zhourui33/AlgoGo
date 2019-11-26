class Node
{
    public:
    int data;
    Node *next;
};

class List
{
    private:
    Node *head;
    public:
    List();
    ~List();
    void Add(int data);
};