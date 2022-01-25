/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** writes a number
*/

void my_putchar(char c);

char *my_put_nbr(int nb)
{
    int stamp = nb;
    int i = 1;

    while (stamp >= 10) {
        stamp /= 10;
        i *= 10;
    }
    while (nb >= 10) {
        my_putchar ((nb / i) + 48);
        nb %= i;
        i /= 10;
    }
    my_putchar(nb + 48);
}
