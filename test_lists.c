/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:22:34 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/09 17:53:52 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void print_list(tNode *p_begin)
{
    tNode *p = p_begin;
    while (p) {
        //распечатать структуру данных
        printf("%s", p->value);
        //шагнуть вперед !!!
        p = p->next;
    }
}

tNode* ft_to_the_last(tNode **head)
{
    tNode *p = NULL;
    
    p = *head;
    p = p->next;
    p->next = NULL;
    return (p);
}

tNode* ft_create_list(tNode **head)
{
    int i;
    // tNode *p_begin = NULL;
    tNode *p;
    
    p = NULL;
    if (!*head)
    {
        *head = (tNode *)malloc(sizeof(tNode));
        p = *head;
        p->next = NULL;
    }
    else
    {
        p = *head;
        while (p->next)
            p = p->next;
        p->next = (tNode *)malloc(sizeof(tNode));
        p = p->next;
        p->next = NULL;
    }
    return (p);
}