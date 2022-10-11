#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Node
{
    int val;
    Node *next;

    Node(int x)
    {
        val = x;
        next = nullptr;
    }
};

Node *getLinkedList(int n)
{
    Node *start = new Node(1);
    Node *head = start;

    for (int i = 2; i <= n; i++)
    {
        start->next = new Node(i);
        start = start->next;
    }

    start->next = head;

    return head;
}

void displayLinkedList(Node *start)
{
    Node *head = start;
    cout << start->val << " ";
    start = start->next;
    while (start != head)
    {
        cout << start->val << " ";
        start = start->next;
    }
}

int getWinner(int n)
{
    Node *head = getLinkedList(n);

    Node *temp = head;

    while (temp->next->next != temp)
    {
        temp->next = temp->next->next;
        temp = temp->next;
    }

    return temp->val;
}

int getWinnerRecursion(int n)
{
    if (n == 1 || n == 2)
        return 1;
    if (n == 3)
        return 3;

    if (n % 2 == 0)
        return 2 * getWinnerRecursion(n / 2) - 1;
    else
        return 2 * getWinnerRecursion(n / 2) + 1;
}

int getWinnerBitMan(int n)
{
    int temp = n;
    int count = 0;
    while (temp - temp / 2 > 0)
    {
        count++;
        temp = temp >> 1;
    }
    return 2 * (n - pow(2, count - 1)) + 1;
}

int main()
{
    int n;
    cout << "Enter number of players:";
    cin >> n;

    cout << "Here is your answer:\n";

    cout << getWinnerRecursion(n) << "\n";

    return 0;
}