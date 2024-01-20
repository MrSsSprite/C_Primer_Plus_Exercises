/**
 * @file    ex11.c
 * @brief   Grocery Online Shop
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ARTICHOKES_PRICE  2.05
#define BEETS_PRICE       1.15
#define CARROTS_PRICE     1.09
#define DISCOUNT_RATE 0.05

void prompt_menu(void)
{
  printf("**********************************************\n"
         "Enter an appropriate character to buy an item:\n");
  printf("a) artichokes,        b) beets,\n"
         "c) carrots,           q) Quit\n");
  printf("**********************************************\n");
}

int main(void)
{
  const char *GOOD_NAME[3] =
  {
    "artichoke", "beet", "carrot"
  };
  int artichoke_pound = 0, beet_pound = 0, carrot_pound = 0;
  char cmd;
  int *dest = 0;

  // add goods to cart
  while (prompt_menu(),
         (cmd = getchar()) != 'q')
  {
    switch (cmd)
    {
    case 'a':
      dest = &artichoke_pound;
      break;
    case 'b':
      dest = &beet_pound;
      break;
    case 'c':
      dest = &carrot_pound;
      break;
    default:
      printf("Invalid Input\n");
      while (getchar() != '\n');
      continue;
    }

    int value;
    printf("Input the weight in pound: ");
    if (scanf("%d", &value) != 1)
      printf("Error: request not accepted\n");
    else
    {
      *dest += value;
      printf("%d pounds of %s added to the cart (total in cart: %d)\n",
             value, GOOD_NAME[cmd - 'a'], *dest);
    }

    while (getchar() != '\n');
  }

  // compute the grand charges
  float gross_cost = artichoke_pound * ARTICHOKES_PRICE
                   + beet_pound * BEETS_PRICE
                   + carrot_pound * CARROTS_PRICE;
  bool discount_activated = false;
  if (gross_cost >= 100.0)
    discount_activated = true;

  float costs[3] =
  {
    artichoke_pound * ARTICHOKES_PRICE,
    beet_pound * BEETS_PRICE,
    carrot_pound * CARROTS_PRICE
  };
  if (discount_activated)
    for (int i = 0; i < 3; i++)
      costs[i] *= (1 - DISCOUNT_RATE);
  printf("Goods in the card:\n");
  if (discount_activated)
    printf("(Discount Activated: %.1f%%)\n", DISCOUNT_RATE * 100.0);
  if (artichoke_pound)
    printf("%*s($%4.2f/pound): %d pounds, $%.2f\n",
           strlen(GOOD_NAME[0]), GOOD_NAME[0],
           ARTICHOKES_PRICE, artichoke_pound,
           costs[0]);
  if (beet_pound)
    printf("%*s($%4.2f/pound): %d pounds, $%.2f\n",
           strlen(GOOD_NAME[0]), GOOD_NAME[1],
           BEETS_PRICE, beet_pound,
           costs[1]);
  if (carrot_pound)
    printf("%*s($%4.2f/pound): %d pounds, $%.2f\n",
           strlen(GOOD_NAME[0]), GOOD_NAME[2],
           CARROTS_PRICE, carrot_pound,
           costs[2]);

  int total_pound = artichoke_pound + beet_pound + carrot_pound;
  float shipment_cost;
  if (total_pound <= 5)
    shipment_cost = 6.50;
  else if (total_pound < 20)
    shipment_cost = 14.00;
  else
    shipment_cost = 14.00 + 0.50 * total_pound;
  if (discount_activated)
    shipment_cost *= 1 - DISCOUNT_RATE;
  printf("Shipment Cost: %.1f\n", shipment_cost);
  
  printf("Total Cost: %f\n", costs[0] + costs[1] + costs[2] + shipment_cost);

  return 0;
}
