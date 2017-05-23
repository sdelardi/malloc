/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 09:46:09 by sdelardi          #+#    #+#             */
/*   Updated: 2016/02/25 20:57:42 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <float.h>
# define PRED "\x1b[31m"
# define PGREEN "\x1b[32m"
# define PYELLOW "\x1b[33m"
# define PBLUE "\x1b[34m"
# define PMAGENTA "\x1b[35m"
# define PCYAN "\x1b[36m"
# define PLRED "\x1b[1;31m"
# define PLGREEN "\x1b[1;32m"
# define PLYELLOW "\x1b[1;33m"
# define PLBLUE "\x1b[1;34m"
# define PLMAGENTA "\x1b[1;35m"
# define PLCYAN "\x1b[1;36m"
# define PRESET "\x1b[0m"

typedef struct		s_part
{
	unsigned long	mantisa : 52;
	unsigned long	exponent : 11;
	unsigned long	sign : 1;
}					t_part;

union				u_double
{
	double			d;
	t_part			parts;
	unsigned long	u;
};

typedef struct		s_printf
{
	char			is_zero;
	size_t			nbr_zero;
	char			is_minus;
	size_t			nbr_minus;
	char			is_plus;
	char			is_space;
	size_t			nbr_space;
	char			is_hash;
	char			is_preci;
	int				nbr_preci;
	char			is_field;
	int				nbr_field;
	char			*modifier;
	char			*instr;
	int				*count;
	char			conversion;
	int				print;
}					t_printf;

/*
** FONCTION FT_PRINTF
*/
int					ft_printf(const char *format, ...);
int					ptf_process_conversion(char *str, va_list ap, int *count);
void				ptf_process_instruction(t_printf *ptr, va_list ap);
int					ptf_flag_control(t_printf *ptr, int index);
int					ptf_preci_field_controller(t_printf *ptr, int index,
		va_list ap);
void				ptf_modifier_controller(t_printf *ptr, char *modif);
void				ptf_pad_after(t_printf *ptr, int length);
void				ptf_controller_di(t_printf *ptr, va_list ap);
void				ptf_controller_u(t_printf *ptr, va_list ap);
void				ptf_controller_b(t_printf *ptr, va_list ap);
void				ptf_controller_o(t_printf *ptr, va_list ap);
void				ptf_controller_xp(t_printf *ptr, va_list ap);
void				ptf_controller_cs(t_printf *ptr, va_list ap);
void				ptf_controller_f(t_printf *ptr, va_list ap);
void				ptf_controller_a(t_printf *ptr, va_list ap);
void				ptf_controller_e(t_printf *ptr, va_list ap);
void				ptf_controller_n(t_printf *ptr,
		va_list ap, int count);
void				ptf_printfwstr(t_printf *ptr, wchar_t *str);
int					ptf_is_flag(char *instr);
int					ptf_is_preci(char *instr);
int					ptf_is_modifier(char *instr);
void				ptf_print_float(float nbr, t_printf *ptr);
void				ptf_print_field_c(t_printf *ptr);
void				ptf_print_flag_c(t_printf *ptr);
void				ptf_print_field_e(t_printf *ptr, double nbr);
void				ptf_print_flag_e(t_printf *ptr, int *check);
void				ptf_print_field_f(t_printf *ptr, double nbr);
double				ptf_print_flag_f(t_printf *ptr, double nbr);
int					ptf_process_colors(char *str, int *count);
void				recu_print_time(unsigned long int time,
		int index, t_printf *ptr);
void				ptf_print_f(double nbr, t_printf *ptr);
char				*ft_itoa_base(long long int value, int base);
char				*ft_uitoa_base(unsigned long long int value, int base);
int					count_nb_octet(wchar_t letter);
int					strlen_wchar(wchar_t *str);
int					ft_putwchar(wchar_t letter);
int					count_significant_bit(int value);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_putchar(char c);
int					ft_putstr(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_round(double d);
void				ft_strdel(char **as);
size_t				ft_strlen(const char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
int					ft_isspace(int c);
int					ft_isalpha(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strcpy(char *dst, const char *src);

#endif
