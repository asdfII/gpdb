/*-------------------------------------------------------------------------
 *
 * subselect.h
 *
 * Portions Copyright (c) 2006-2008, Greenplum inc
 * Portions Copyright (c) 1996-2008, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $PostgreSQL: pgsql/src/include/optimizer/subselect.h,v 1.30 2008/01/01 19:45:58 momjian Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef SUBSELECT_H
#define SUBSELECT_H

#include "nodes/plannodes.h"
#include "nodes/relation.h"
extern bool convert_ANY_sublink_to_join(PlannerInfo *root, SubLink *sublink,
                                                                               Relids available_rels,
                                                                               Node **new_qual, List **fromlist);
extern bool convert_EXISTS_sublink_to_join(PlannerInfo *root, SubLink *sublink,
                                                                                  bool under_not,
                                                                                  Relids available_rels,
                                                                                  Node **new_qual, List **fromlist);
// 8.4-9.0-MERGE-FIX-ME The below function convert_IN_to_join and convert_testexpr
// does not exists in commit 19e34b62395b36513a8e6c35ddfbeef12dd1e89f
extern Node *convert_IN_to_join(PlannerInfo *root, List **rtrlist_inout, SubLink *sublink);
extern Node *convert_testexpr(PlannerInfo *root,
				 Node *testexpr,
				 List *subst_nodes);
extern Node *SS_replace_correlation_vars(PlannerInfo *root, Node *expr);
extern Node *SS_process_sublinks(PlannerInfo *root, Node *expr, bool isQual);
extern void SS_finalize_plan(PlannerInfo *root, Plan *plan,
							 bool attach_initplans);
extern Param *SS_make_initplan_from_plan(PlannerInfo *root, Plan *plan,
						   Oid resulttype, int32 resulttypmod);

extern bool IsSubqueryCorrelated(Query *sq);
extern bool IsSubqueryMultiLevelCorrelated(Query *sq);

extern List *generate_subquery_vars(PlannerInfo *root, List *tlist,
					   Index varno);

#endif   /* SUBSELECT_H */
