#include<stdio.h>
#include "library.h"

void libraryMenu()
{
    struct Book book[100];
    int count = 0;
    int ch;
    do{
        printf("\n===== LIBRARY MANAGEMENT =====\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Save Books\n");
        printf("7. Load Books\n");
        printf("8. Back\n");

        printf("Enter choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                addBook(book,&count);
                break;

            case 2:
                viewBook(book,count);
                break;

            case 3:
                searchBook(book,count);
                break;

            case 4:
                updateBook(book,count);
                break;

            case 5:
                deleteBook(book,&count);
                break;

            case 6:
                saveBook(book,count);
                break;

            case 7:
                loadBook(book,&count);
                break;

            case 8:
                printf("back to main");
                break;

            default:
                printf("Invalid input");
                break;

        }


    }while(ch!=8);
}
void addBook(struct Book *book,int *count)
{
    printf("Enter Book ID: ");
    scanf("%d", &book[*count].bookId);

    printf("Enter Book Title: ");
    scanf("%s", book[*count].title);

    printf("Enter Author Name: ");
    scanf("%s", book[*count].author);

    printf("Enter Quantity: ");
    scanf("%d", &book[*count].quantity);

    (*count)++;

    printf("\nBook Added Successfully!\n");
}
void viewBook(struct Book *book,int count)
{
    if(count==0)
    {
        printf("No Book");
        return;
    }
    for(int i=0;i<count;i++)
    {
        printf("\n=======Library Book======\n");
        printf("Book Id        : %d\n",book[i].bookId);
        printf("Book title     : %s\n",book[i].title);
        printf("Book author    : %s\n",book[i].author);
        printf("Book quatity   : %d\n",book[i].quantity);
        printf("\n===========================\n");
    }
}
void searchBook(struct Book *book,int count)
{
    int key;
    int found = 0;

    if(count==0){
        printf("No faculty");
        return;
    }
    printf("Enter Id to search:");
    scanf("%d",&key);

    for(int i=0;i<count;i++)
    {
        if(key==book[i].bookId)
        {
            found=1;
            printf("\n=======Library Book======\n");
            printf("Book Id        : %d\n",book[i].bookId);
            printf("Book title     : %s\n",book[i].title);
            printf("Book author    : %s\n",book[i].author);
            printf("Book quatity   : %d\n",book[i].quantity);
            printf("\n===========================\n");
        }
    }
    if(found==0){
        printf("Book not found");
        return;
    }
}
void updateBook(struct Book *book, int count)
{
    if(count==0)
    {
        printf("No books");
        return;
    }
    int key;
    printf("Enter Book id to update:");
    scanf("%d",&key);
    int found=0;
    for(int i=0;i<count;i++)
    {
        if(key==book[i].bookId)
        {
            found=1;
            printf("Enter New Title: ");
            scanf("%s", book[count].title);

            printf("Enter Author Name: ");
            scanf("%s", book[count].author);

            printf("Enter Quantity: ");
            scanf("%d", &book[count].quantity);

        }
    }
    if(found==0)
    {
        printf("Book not found");
    }
}
void deleteBook(struct Book *book,int *count)
{
    if(*count==0)
    {
        printf("No Book");
        return;
    }
    int key;
    printf("Enter Book Id to delete:");
    scanf("%d",&key);

    int found=0;

    for(int i=0;i<*count;i++)
    {
        if(key==book[i].bookId)
        {
            found=1;
            for(int j=i;j<*count-1;j++)
            {
                book[j]=book[j+1];
            }
            (*count)--;
            printf("Book deleted successfully.");
            break;
        }
    }
    if(!found)
    {
        printf("Book not found");
    }
}
void saveBook(struct Book *book,int count)
{
    FILE *fp=fopen("library.txt","w");
    if(fp == NULL)
    {
        printf("Cannot open file!\n");
        return;
    }

    fprintf(fp, "%d\n", count);  

    for(int i=0;i<count;i++)
    {
        fprintf(fp,"%d %s %s %d\n",
        book[i].bookId,
        book[i].title,
        book[i].author,
        book[i].quantity);
    }
    fclose(fp);

    printf("Book saved successfully");
}
void loadBook(struct Book *book,int *count)
{
    FILE *fp=fopen("library.txt","r");
    if(fp==NULL)
    {
        printf("cannot open file.");
        return;
    }
    fscanf(fp,"%d",count);
    for(int i=0;i<count;i++)
    {
        fscanf(fp,"%d,%49s,%49s,%d\n",
        &book[i].bookId,
        book[i].title,
        book[i].author,
        &book[i].quantity);
    }
    fclose(fp);
    printf("Book load successfully!.");


}
