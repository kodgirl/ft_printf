/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:52:54 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/26 18:14:17 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef PRINTF_H
#   define PRINTF_H

#   include <stdarg.h>
#   include <stdlib.h>
#   include <stdio.h>
#   include <unistd.h>
#	include <string.h>
#	include <inttypes.h>
#	include <limits.h>
#	include <math.h>

# define MAX_SIZE_BUF       16500 //5000
# define MAX_INTEGER_SIZE	4934
# define MAX_FRACT_SIZE		16500 //16383

typedef struct              s_float
{
    char                   integer[MAX_INTEGER_SIZE];
    char                   fract[MAX_FRACT_SIZE];
    int                    size_int;
    int                    size_fract;
    int                    fract_length;
}                           t_float;

typedef union               s_print		    
{
    long double             number;
    struct                 
    {
        unsigned long long  mant:64;
	    short int           exp:15;
	    unsigned int        sign:1;
    }                       t_byte;
}						    t_print;

typedef enum                e_boolen
{
    True = 1,
    False = !True
}                           t_boolen;

typedef struct              s_buf_power
{
    char buf[MAX_SIZE_BUF];
    int power;
    t_boolen init;
}                           t_buf_power;

typedef struct              s_power_of_2
{
    int integer[64];
    int fract[64];
    int size_int;
    int size_fract;
}                           t_power_of_2;

typedef struct  s_struct
{
    char type;
	int castilok; // тот самый фикс возврата чара
    int stop; // костыль для парса
    int plus; //f
    int minus; //f
    int space; //f
    int sharp; //f
    int zero; //f
    int stopflags; // стоп флагов
    int width;
	int widthisneg; // ширина отрицательная
    int precision; // точность
    intmax_t value_d; // значение из стэка для d/i
    long double value_f;
    unsigned char value_hex[25];
    int h;
    int hh;
    int l;
    int ll;
    int value_is_neg;
    int dack_prec;
    int null_for_c;
    int s_len;
    char *govno;
	int final_size; // общий размер строки за одну обработку!
	int nan_or_inf;
}               t_struct;

typedef struct s_buff
{
	size_t size_of_all; // каждый раз после обработки считаем сумму
    size_t previous_len; 
    size_t size_lists;
    int flag;
    int test;
}              t_buff;

int ft_printf(const char *format, ...);
int not_arg_searcher(char *format, t_buff *buff_size);
int ft_text(char *format, int i, t_buff *buff_size);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
// парсер+-
void	*ft_memalloc(size_t size);
char	*ft_strcat(char *s1, const char *s2, t_struct *inform);
//
int ft_type(char *format, va_list list, t_buff *buff_size);
int ft_precision(t_struct *inform, char *format, int stop, t_buff *buff_size, va_list list);
int	ft_new_atoi(const char *str, int start, int end);
char		*ft_short_itoa(unsigned short int n);
int ft_width(t_struct *inform, char *format, int formodifiers, t_buff *buff_size, va_list list);
int ft_modifiers(char *format, t_struct *inform, int stop, t_buff *buff_size, va_list list);
void ft_make_arg(t_struct *inform, t_buff *buff_size, int len);
int ft_value_maker(t_struct *inform, t_buff *buff_size, va_list list);
int     ft_value_d(t_struct *inform, va_list list, int i); // для di
int ft_value_u(t_struct *inform, va_list list, int i); // для u
int ft_value_f(t_struct *inform, va_list list, int i);
int int_len(long int value, t_struct *inform); // для diu
int ul_int_len(unsigned long int value, t_struct *inform); // для u
int us_int_len(unsigned short int value, t_struct *inform); // for short u
char *d_value_maker(t_struct *inform, char *buffer); // для di
char *u_value_maker(t_struct *inform, char *buffer); // для u
char *o_value_maker(t_struct *inform, char *buffer);
char *s_value_maker(t_struct *inform, char *buffer);
char *p_value_maker(t_struct *infrom, char *buffer);
int ft_value_o(t_struct *inform, va_list list, int i); // для o
int ft_value_x(t_struct *inform, va_list list, int i);
char *word_maker(t_struct *inform, char *buffer, int len);
int va_value(t_struct *inform, va_list list, int i);
void ft_octal(t_struct *inform, int flag); // перевод в восьмиричную 
char		*ft_new_itoa(long int n);
// всякие itoa
char		*ft_long_itoa(unsigned long int n);
char	*ft_long_final(unsigned long int f);
char		*ft_oct_itoa(long n);
int	ft_long_len(unsigned long int f);
void ft_hexer(t_struct *inform, int i);
// обработка с ширины
char *ft_spacer_negative(char *s1, char sym, t_struct *inform);
char *start_by_width(t_struct *inform, char *buffer, int len);
char *start_by_neg_width(t_struct *inform, char *buffer, int len);
char *start_by_neg_width2(t_struct *inform, char *str, char *buffer, int len, int i);
char *ft_negative_flags(char *str, t_struct *inform);
char *ft_strpcat(char *s1, t_struct *inform, int len); // for p
char *ft_spacer(char *s1, char sym, t_struct *inform, int len);
char *ft_flags(char *str, t_struct *inform, int i, int len);
char *ft_zeroes(char *s1, t_struct *inform, int len);
// обработка с точности
char *start_by_prec(t_struct *inform, char *buffer, int len);
// обработка с длины
char *start_by_len(t_struct *inform, char *buffer, int len);
// буффер
char	*ft_strfncat(char *s1, const char *s2, size_t n);
char	*ft_strfromcat(char *s1, const char *s2, size_t len, size_t n);
// hex
int hex_len(long int value, t_struct *inform);
char *hex_rev(t_struct *inform);
// с
char *x_value_maker(t_struct *inform, char *buffer);
int ft_diouxx(t_struct *inform, char sym);
int ft_csp(t_struct *inform, char sym);
int ft_value_c(t_struct *inform, va_list list, int i);
char *c_value_maker(t_struct *inform, char *buffer);
void flag_clear(t_struct *inform);
// s
int ft_value_s(t_struct *inform, va_list list, int i);
char *str_maker(t_struct *inform, char *buffer, int len);
char *ft_widther(t_struct *inform, char *buffer, int len);
char *ft_minus_widther(t_struct *inform, char *buffer, int len);
// p
int ft_value_p(t_struct *inform, va_list list, int i);
char *p_value_maker(t_struct *infrom, char *buffer);
// f
int f_len(t_struct *inform);
char *f_value_maker(t_struct *infrom, char *buffer);
void    ft_beatuful_mass(char *long_num, int buf_size);
void    ft_mass_sum(char *long_num1, char *long_num2);
void    ft_longnum_to_2power(char *long_num, int power);
void    ft_buf_riseto_power(t_buf_power *buffer, int to_power);
t_float    ft_long_ariphm(t_power_of_2 powers);
void    ft_power_to_massive(t_power_of_2 *powers, int power);
char    *ft_float(long double a, t_struct *flags);
void    ft_mass_multiply(char *buffer, int num);
void    print_float_number(t_float *number, int len_int, int len_fract);
void    print_struct_powers(t_power_of_2 *powers);
void    ft_five_to_power(t_buf_power *buffer, int to_power);
void    ft_fract_sum(t_float *number, t_buf_power *buffer);
void    ft_longnum_to_5power(char *buffer, int power);
void    ft_mass_multiply(char *buffer, int num);
char    *float_tostr(t_float *number, t_struct *flags);
int		ft_sizeint(char *integer, long double value);

void    print_float_number(t_float *number, int len_int, int len_fract);
#endif
