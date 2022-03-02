#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int roll_no;
    char name[20];
    int marks[3];
    struct Node *nxt;
};

//creating start Node pointer
struct Node *start =NULL;

int main()
{
    while(1)
    {
        option();
    }
    return 0;
}
void option()
{
    int i,a;
    system("cls");
    printf("Please select the option:\n1. Insert a student record\n2. Delete a student record\n3. Update a student record\n4. Display record\n5. Exit");
    printf("\n\nYour Option: ");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        system("cls");
        printf("How many records you wish to enter :");
        scanf("%d",&a);
        while(a)
        {
            printf("\nPlease enter roll no. to be inserted :");
            scanf("%d",&i);
            if(search(i) ==0)
            {
                insert();
            }
            else
            {
                printf("\nRoll no is already present in the list.\nDo You want to edit it ?(Y/N)");
                char c;
                fflush(stdin);
                scanf("%c",&c);
                if(c == 'Y')
                {
                    update(i);
                }
            }
            a--;
        }
        //printf("\nPress any button to continue");
        system("pause");
        break;
    case 2:
        printf("\nPlease enter roll no. to be deleted :");
        scanf("%d",&a);
        if(search(a)==1)
        {
            del(a);
        }
        else
        {
            printf("\nNo record found.\n");
        }
        system("pause");
        break;
    case 3:
        printf("\nPlease enter roll no. to be updated :");
        scanf("%d",&a);
        if(search(a)==1)
        {
            update(a);
        }
        else
        {
            printf("\nNo record found.\n");
        }
        system("pause");
        break;
    case 4:
        printf("\n1.Display All Records\n2.Display A particular record\n\nYour Choice :");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                printf("\nList of Students:\n");
                print();
                break;

            case 2:
                print_record();
                break;

            default:
                printf("Wrong Choice");

        }
        //printf("\nPress any button to continue");
        system("pause");
        break;
    case 5:
        printf("\nThankyou for using this program\n");
        exit(0);
    default:
        printf("Wrong Option\n");
        //printf("\nPress any button to continue");
        system("pause");
    }
}

//function to print a particular record
void print_record()
{
    struct Node *t;
    t=start;
    printf("Enter roll no to print its details :");
    int n;
    scanf("%d",&n);
    while(t != NULL && t->roll_no <= n)
    {
        if(t->roll_no == n)
        {
            printf("\nDetails:-\n_______________________________\n");
            printf("Roll no. : %d",t->roll_no);
            printf("\tName : %s\n",t->name);
            printf("_______________________________\n");
            printf("\nEnglish   Maths  Science\n%5d %8d  %7d\n",t->marks[0],t->marks[1],t->marks[2]);
            printf("_______________________________\n");
            return;
        }
        t = t->nxt;
    }
    printf("\nNo record found\n");

}
//function to insert a node at relavent position
void insert(int roll_no)
{
    //creating a struct Node to insert
    struct Node *tmp;
    tmp =(struct Node*)malloc(sizeof(struct Node));

    printf("Enter Name of the student :");
    scanf("%s",tmp->name);

    printf("Enter Marks of 3 subjects:\nEnglish:");
    scanf("%d",&tmp->marks[0]);
    printf("Maths:");
    scanf("%d",&tmp->marks[1]);
    printf("Science :");
    scanf("%d",&tmp->marks[2]);

    tmp->roll_no=roll_no;

    //taking a pointer to traverse
    //throughout the list
    struct Node *t;
    t=start;
    if(start) //checking if list has any item
    {
        //checking if roll_no is for first place
        if(t->roll_no > roll_no)
        {
            tmp->nxt=t;
            start = tmp;
            return;
        }

        //checking and inserting at relavent position
        while(t->nxt != NULL && t->nxt->roll_no < roll_no)
        {
            t = t->nxt;
        }
        tmp->nxt=t->nxt;
        t->nxt = tmp;
    }
    else  //when list doesn't have any item
    {
        start = tmp;
        tmp->nxt=NULL;
    }

    printf("\nRecord Inserted Successfully.\n");
}

//function to print elements of linked list
void print()
{
    struct Node *t=start;
    printf("Roll No  Name          Marks\n--------------------------------------\n");
    while(t != NULL)
    {
        printf("%3d %10s %5d %5d %5d\n",t->roll_no,t->name,t->marks[0],t->marks[1],t->marks[2]);
        t=t->nxt;
    }
    printf("\n--------------------------------------\n");
}

//function to search an item in list
int search(int n)
{
    struct Node *t;
    t=start;
    while(t != NULL && t->roll_no <= n)
    {
        //printf("%d",t->roll_no == n);
        if(t->roll_no == n)
        {
            //printf("yes");
            return 1;
        }
        t=t->nxt;
    }
    return 0;
}

//function to delete an item from list
void del(int n)
{
    struct Node *t,*f;
    t=start;

    //if first element has to be deleted
    if(t->roll_no == n)
    {
        f=start;
        start=start->nxt;
        free(f);
        return;
    }


    //if element to be deleted is anywhere after 1st item
    while(t)
    {
        if(t->nxt->roll_no == n)
        {
            f=t->nxt;
            t->nxt = t->nxt->nxt;
            free(f);
            printf("Record Deleted Successfully.\n");
            return;
        }
        t=t->nxt;
    }
}

//function to update
void update(int n)
{
    struct Node *t;
    t=start;
    while(t->roll_no != n)
        t = t->nxt;
    printf("\n1.Update name\n2.Update marks\n3.Update Both\nYour option :");
    int i;
    scanf("%d",&i);
    label:
    switch(i)
    {
    case 1:
        printf("Enter New Name :");
        scanf("%s",t->name);
        printf("Name Updated successfully.\n");
        break;
    case 2:
        printf("Enter Marks of Engish Maths Science respectively :");
        scanf("%d%d%d",&t->marks[0],&t->marks[1],&t->marks[2]);
        printf("Marks Updated successfully.\n");
        break;
    case 3:
        printf("Enter New Name :");
        scanf("%s",t->name);
        printf("Enter Marks of Engish Maths Science respectively :");
        scanf("%d%d%d",&t->marks[0],&t->marks[1],&t->marks[2]);
        printf("Name Updated successfully.\n");
        break;
    default:
        printf("Wrong Choice. Please try Again.\n");
        goto label;
    }

}
