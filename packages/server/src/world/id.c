/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

bool add_id(int **ids, int const id)
{
    int *tmp = *ids;
    unsigned int len = 0;
    int *new = NULL;

    if (tmp)
         for (unsigned int j = 0; tmp[j]; ++j)
             ++len;
    new = malloc(sizeof(char) * (len + 2));
    if (!new)
         return (false);
    while(tmp && -1 != tmp[i]) {
         new[i] = tmp[i];
         ++i;
    }
    new[i] = id;
    new[i + 1] = -1;
    free(*ids);
    *ids = new;
    return (true);
}

static bool realloc_ids(int **ids, unsigned int const len, int const id)
{
    int *new = malloc(sizeof(int) * (len));
    unsigned int y = 0;

    if (!new)
         return (false);
    for (unsigned int i = 0; -1 != *ids[i]; ++i)
         if (id != *ids[i]) {
             new[y] = *ids[i];
             ++y;
         }
    new[len - 1] = -1;
    free(*ids);
    *ids = new;
}

bool rm_id(int **ids, int const id)
{
    int *tmp = *ids;
    unsigned int len = 0;
    int *new = NULL;
         
    if (!tmp)
        return (true);
    for (unsigned int i = 0; -1 != tmp[i]; ++i)
        ++len;
    if (1 == len)
        free(*ids);
    else if (!realloc_ids(ids, len, id))
        return (false);
    return (true);
}
