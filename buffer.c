/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:58:10 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/10 18:45:29 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "printf.h"

// void part_list_writer(char *str, t_buff *buff_size, size_t len)
// {
//     tNode *new;
//     if (buff_size->size_of_all - len >= buff_size->size_lists) //  если нужен новый лист
//     {
//         new = ft_create_list(&buff_size->p_head);
//         ft_bzero(new->value, SIZE);
//         buff_size->size_lists += SIZE;
//         ft_strcat(new->value, str, inform->dack_prec);
//         return;
//     }
//     else if (buff_size->size_of_all > buff_size->size_lists) // если можно записать частично в оставшийся
//     {
//         if (buff_size->size_of_all - len < buff_size->size_lists)
//         {
//             new = ft_to_the_last(&buff_size->p_head);
//             ft_strfncat(new->value, str, buff_size->size_lists - (buff_size->size_of_all - len));
//             if (len - buff_size->size_lists - (buff_size->size_of_all - len < SIZE))
//             {
//                 new = ft_to_the_last(&buff_size->p_head);
//                 new = ft_create_list(&buff_size->p_head);
//                 ft_strfromcat(new->value, str, len, buff_size->size_lists - (buff_size->size_of_all - len));
//                 return;
//             }
//         }
//         new = ft_create_list(&buff_size->p_head);
//         buff_size->size_lists += SIZE;
//         ft_strcat(new->value, str);
//         return;
//     }
// }

// void make_first_list(char *str, t_buff *buff_size, size_t len)
// {
//     int i;
    
//     i = 0;
    
//     if (buff_size->flag)
//     {
//         buff_size->p_begin = ft_create_list(&buff_size->p_head);
//         buff_size->p_head = buff_size->p_begin;
//         buff_size->flag = 0;
//         ft_bzero(buff_size->p_begin->value, SIZE); 
//     }
//     buff_size->size_of_all += len;
//     if (buff_size->size_lists >= buff_size->size_of_all)
//         ft_strcat(buff_size->p_begin->value, str);
//     else if (buff_size->size_lists < buff_size->size_of_all)
//         part_list_writer(str, buff_size, len);
//     //printf("%s", buff_size->p_begin->value);
//     //printf("\nRAZMER %d\n", buff_size->size_of_all);
// }