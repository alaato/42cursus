#include "./libft.h"
#include "./structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// init
void	add_node(t_stack *stack, t_node *node);
int		init_stack(t_stack *stack, char name);
t_node	*create_node(int value);
void	print_stack(t_stack *stack);

// operations
void	push(t_stack *from, t_stack *to);
void	swap(t_stack *stack);
t_node	*extract_node(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

// find_median.c
int		find_median(t_stack *stack);
void	list_to_arr(int arr[], t_stack *stack);

// sort.c
void	set_min_max(int *min, int *max, t_node *head);
void	sort5(t_stack *a, t_stack *b);
void	sort3(t_stack *stack);
void	sort2(t_stack *stack);
void	set_min_max(int *min, int *max, t_node *head);
int		is_sorted(t_stack *stack);
void	sort(t_stack *a, t_stack *b);

// parse.c
void	fill_stack(t_stack *stack, char *input);
void	fill_stack_many_args(int count, char **args, t_stack *stack);
int		str_to_int(char *str, int numbers[], int len);

// init.c
int		init_program(t_program *program, t_stack *a, t_stack *b);
