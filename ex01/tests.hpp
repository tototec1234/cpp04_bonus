/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:00:00 by toruinoue        #+#    #+#             */
/*   Updated: 2025/01/27 22:00:00 by toruinoue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
#define TESTS_HPP

// テスト関数の宣言
// 実験計画法的アプローチ：2つの核心問題に焦点を絞ったテスト
void testSubjectRequiredBasic();
void testDeepCopy();
void testVirtualPolymorphismProblem();
void testShallowCopyProblem();
void testWrongShallowCopy();
void testAssignmentOperator();
void testExceptionHandling();

#endif
