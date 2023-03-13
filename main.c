#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *down;
    struct Node *right;
};

void Print_grid(struct Node *p)
{
    while (p != NULL)
    {
        printf("%c    %c    %c", p->data, (p->right)->data, ((p->right)->right)->data);
        printf("\n\n");
        p = p->down;
    }
}

int check_hori(struct Node *p)
{
    while (p != NULL)
    {
        if (p->data == (p->right)->data && (p->right)->data == ((p->right)->right)->data)
        {
            return 1;
        }
        else
            p = p->down;
    }
    return 0;
}

int verticalCheck(struct Node *p)
{
    while (p != NULL)
    {
        if (p->data == (p->down)->data && (p->down)->data == ((p->down)->down)->data)
        {
            return 1;
        }
        else
            p = p->right;
    }
    return 0;
}

int diagonalCheck(struct Node *p)
{
    if (p->data == ((p->down)->right)->data && ((p->down)->right)->data == ((((p->down)->right)->down)->right)->data)
    {
        return 1;
    }
    else if (((p->down)->down)->data == ((p->down)->right)->data && ((p->down)->right)->data == ((p->right)->right)->data)
    {
        return 1;
    }
    return 0;
}

int Match(struct Node *p)
{
    if (check_hori(p) || verticalCheck(p) || diagonalCheck(p))
        return 0;
    else
        return 1;
}

int position(struct Node *p, int x, int y)
{
    int i = 0;
    while (i < x)
    {
        p = p->right;
        i++;
    }
    i = 0;
    while (i < y)
    {
        p = p->down;
        i++;
    }
    if (p->data == '_')
        return 1;
    else
    {
        printf("\nThis place is already occupied.\nChoose another co-ordinate.\n");
        return 0;
    }
}

void input_pos(struct Node *p, int x, int y, int val)
{
    int i = 0;

    while (i < x)
    {
        p = p->right;
        i++;
    }
    i = 0;
    while (i < y)
    {
        p = p->down;
        i++;
    }
    if (val == 1)
        p->data = 'X';
    else
        p->data = 'O';
}

int main()
{

    struct Node *node1, *node2, *node3,
        *node4, *node5, *node6,
        *node7, *node8, *node9;

    node1 = (struct Node *)malloc(sizeof(struct Node));
    node2 = (struct Node *)malloc(sizeof(struct Node));
    node3 = (struct Node *)malloc(sizeof(struct Node));
    node4 = (struct Node *)malloc(sizeof(struct Node));
    node5 = (struct Node *)malloc(sizeof(struct Node));
    node6 = (struct Node *)malloc(sizeof(struct Node));
    node7 = (struct Node *)malloc(sizeof(struct Node));
    node8 = (struct Node *)malloc(sizeof(struct Node));
    node9 = (struct Node *)malloc(sizeof(struct Node));

    node1->data = '_';
    node1->right = node2;
    node1->down = node4;
    node2->data = '_';
    node2->right = node3;
    node2->down = node5;
    node3->data = '_';
    node3->right = NULL;
    node3->down = node6;
    node4->data = '_';
    node4->right = node5;
    node4->down = node7;
    node5->data = '_';
    node5->right = node6;
    node5->down = node8;
    node6->data = '_';
    node6->right = NULL;
    node6->down = node9;
    node7->data = '_';
    node7->right = node8;
    node7->down = NULL;
    node8->data = '_';
    node8->right = node9;
    node8->down = NULL;
    node9->data = '_';
    node9->right = NULL;
    node9->down = NULL;

    int k = 9, flag = 1, j = 1, f = 1;

    Print_grid(node1);
    while ((k) && flag)
    {
        printf("Enter Co-ordinates: ");
        int x, y;
        scanf("%d %d", &y, &x);
        f = position(node1, x, y);
        if (f)
        {
            input_pos(node1, x, y, (j % 2));
            if (j > 4)
                flag = Match(node1);
            j++;
            k--;
        }

        f = 1;
        Print_grid(node1);
    }
    if (flag)
        printf("\nDRAW!!\n");
    else
    {
        if ((j) % 2 == 0)
            printf("\nX wins!!!\n");
        else
            printf("\nO wins!!!\n");
    }

    return 0;
}