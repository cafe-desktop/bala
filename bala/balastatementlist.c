/* balastatementlist.c generated by balac, the Bala compiler
 * generated from balastatementlist.bala, do not modify */

/* balastatementlist.bala
 *
 * Copyright (C) 2008-2010  Jürg Billeter
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Jürg Billeter <j@bitron.ch>
 */

#include "bala.h"
#include <balagee.h>
#include <glib-object.h>
#include <glib.h>

#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))
#define _bala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_code_node_unref (var), NULL)))

struct _BalaStatementListPrivate {
	BalaList* list;
};

static gint BalaStatementList_private_offset;
static gpointer bala_statement_list_parent_class = NULL;
static BalaStatementIface * bala_statement_list_bala_statement_parent_iface = NULL;

static void bala_statement_list_real_get_error_types (BalaCodeNode* base,
                                               BalaCollection* collection,
                                               BalaSourceReference* source_reference);
static void bala_statement_list_real_accept (BalaCodeNode* base,
                                      BalaCodeVisitor* visitor);
static gboolean bala_statement_list_real_check (BalaCodeNode* base,
                                         BalaCodeContext* context);
static void bala_statement_list_real_emit (BalaCodeNode* base,
                                    BalaCodeGenerator* codegen);
static void bala_statement_list_finalize (BalaCodeNode * obj);
static GType bala_statement_list_get_type_once (void);

static inline gpointer
bala_statement_list_get_instance_private (BalaStatementList* self)
{
	return G_STRUCT_MEMBER_P (self, BalaStatementList_private_offset);
}

gint
bala_statement_list_get_length (BalaStatementList* self)
{
	gint result;
	BalaList* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = self->priv->list;
	_tmp1_ = bala_collection_get_size ((BalaCollection*) _tmp0_);
	_tmp2_ = _tmp1_;
	result = _tmp2_;
	return result;
}

BalaStatementList*
bala_statement_list_construct (GType object_type,
                               BalaSourceReference* source_reference)
{
	BalaStatementList* self = NULL;
	self = (BalaStatementList*) bala_code_node_construct (object_type);
	bala_code_node_set_source_reference ((BalaCodeNode*) self, source_reference);
	return self;
}

BalaStatementList*
bala_statement_list_new (BalaSourceReference* source_reference)
{
	return bala_statement_list_construct (BALA_TYPE_STATEMENT_LIST, source_reference);
}

BalaStatement*
bala_statement_list_get (BalaStatementList* self,
                         gint index)
{
	BalaList* _tmp0_;
	gpointer _tmp1_;
	BalaStatement* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->list;
	_tmp1_ = bala_list_get (_tmp0_, index);
	result = (BalaStatement*) _tmp1_;
	return result;
}

void
bala_statement_list_set (BalaStatementList* self,
                         gint index,
                         BalaStatement* stmt)
{
	BalaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (stmt != NULL);
	_tmp0_ = self->priv->list;
	bala_list_set (_tmp0_, index, stmt);
}

void
bala_statement_list_add (BalaStatementList* self,
                         BalaStatement* stmt)
{
	BalaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (stmt != NULL);
	_tmp0_ = self->priv->list;
	bala_collection_add ((BalaCollection*) _tmp0_, stmt);
}

void
bala_statement_list_insert (BalaStatementList* self,
                            gint index,
                            BalaStatement* stmt)
{
	BalaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (stmt != NULL);
	_tmp0_ = self->priv->list;
	bala_list_insert (_tmp0_, index, stmt);
}

static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

static void
bala_statement_list_real_get_error_types (BalaCodeNode* base,
                                          BalaCollection* collection,
                                          BalaSourceReference* source_reference)
{
	BalaStatementList * self;
	self = (BalaStatementList*) base;
	g_return_if_fail (collection != NULL);
	{
		BalaList* _stmt_list = NULL;
		BalaList* _tmp0_;
		BalaList* _tmp1_;
		gint _stmt_size = 0;
		BalaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _stmt_index = 0;
		_tmp0_ = self->priv->list;
		_tmp1_ = _bala_iterable_ref0 (_tmp0_);
		_stmt_list = _tmp1_;
		_tmp2_ = _stmt_list;
		_tmp3_ = bala_collection_get_size ((BalaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_stmt_size = _tmp4_;
		_stmt_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			BalaStatement* stmt = NULL;
			BalaList* _tmp7_;
			gpointer _tmp8_;
			BalaStatement* _tmp9_;
			_stmt_index = _stmt_index + 1;
			_tmp5_ = _stmt_index;
			_tmp6_ = _stmt_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _stmt_list;
			_tmp8_ = bala_list_get (_tmp7_, _stmt_index);
			stmt = (BalaStatement*) _tmp8_;
			_tmp9_ = stmt;
			bala_code_node_get_error_types ((BalaCodeNode*) _tmp9_, collection, source_reference);
			_bala_code_node_unref0 (stmt);
		}
		_bala_iterable_unref0 (_stmt_list);
	}
}

static void
bala_statement_list_real_accept (BalaCodeNode* base,
                                 BalaCodeVisitor* visitor)
{
	BalaStatementList * self;
	self = (BalaStatementList*) base;
	g_return_if_fail (visitor != NULL);
	{
		BalaList* _stmt_list = NULL;
		BalaList* _tmp0_;
		BalaList* _tmp1_;
		gint _stmt_size = 0;
		BalaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _stmt_index = 0;
		_tmp0_ = self->priv->list;
		_tmp1_ = _bala_iterable_ref0 (_tmp0_);
		_stmt_list = _tmp1_;
		_tmp2_ = _stmt_list;
		_tmp3_ = bala_collection_get_size ((BalaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_stmt_size = _tmp4_;
		_stmt_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			BalaStatement* stmt = NULL;
			BalaList* _tmp7_;
			gpointer _tmp8_;
			BalaStatement* _tmp9_;
			_stmt_index = _stmt_index + 1;
			_tmp5_ = _stmt_index;
			_tmp6_ = _stmt_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _stmt_list;
			_tmp8_ = bala_list_get (_tmp7_, _stmt_index);
			stmt = (BalaStatement*) _tmp8_;
			_tmp9_ = stmt;
			bala_code_node_accept ((BalaCodeNode*) _tmp9_, visitor);
			_bala_code_node_unref0 (stmt);
		}
		_bala_iterable_unref0 (_stmt_list);
	}
}

static gboolean
bala_statement_list_real_check (BalaCodeNode* base,
                                BalaCodeContext* context)
{
	BalaStatementList * self;
	gboolean result = FALSE;
	self = (BalaStatementList*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	{
		BalaList* _stmt_list = NULL;
		BalaList* _tmp0_;
		BalaList* _tmp1_;
		gint _stmt_size = 0;
		BalaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _stmt_index = 0;
		_tmp0_ = self->priv->list;
		_tmp1_ = _bala_iterable_ref0 (_tmp0_);
		_stmt_list = _tmp1_;
		_tmp2_ = _stmt_list;
		_tmp3_ = bala_collection_get_size ((BalaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_stmt_size = _tmp4_;
		_stmt_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			BalaStatement* stmt = NULL;
			BalaList* _tmp7_;
			gpointer _tmp8_;
			BalaStatement* _tmp9_;
			_stmt_index = _stmt_index + 1;
			_tmp5_ = _stmt_index;
			_tmp6_ = _stmt_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _stmt_list;
			_tmp8_ = bala_list_get (_tmp7_, _stmt_index);
			stmt = (BalaStatement*) _tmp8_;
			_tmp9_ = stmt;
			if (!bala_code_node_check ((BalaCodeNode*) _tmp9_, context)) {
				result = FALSE;
				_bala_code_node_unref0 (stmt);
				_bala_iterable_unref0 (_stmt_list);
				return result;
			}
			_bala_code_node_unref0 (stmt);
		}
		_bala_iterable_unref0 (_stmt_list);
	}
	result = TRUE;
	return result;
}

static void
bala_statement_list_real_emit (BalaCodeNode* base,
                               BalaCodeGenerator* codegen)
{
	BalaStatementList * self;
	self = (BalaStatementList*) base;
	g_return_if_fail (codegen != NULL);
	{
		BalaList* _stmt_list = NULL;
		BalaList* _tmp0_;
		BalaList* _tmp1_;
		gint _stmt_size = 0;
		BalaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _stmt_index = 0;
		_tmp0_ = self->priv->list;
		_tmp1_ = _bala_iterable_ref0 (_tmp0_);
		_stmt_list = _tmp1_;
		_tmp2_ = _stmt_list;
		_tmp3_ = bala_collection_get_size ((BalaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_stmt_size = _tmp4_;
		_stmt_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			BalaStatement* stmt = NULL;
			BalaList* _tmp7_;
			gpointer _tmp8_;
			BalaStatement* _tmp9_;
			_stmt_index = _stmt_index + 1;
			_tmp5_ = _stmt_index;
			_tmp6_ = _stmt_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _stmt_list;
			_tmp8_ = bala_list_get (_tmp7_, _stmt_index);
			stmt = (BalaStatement*) _tmp8_;
			_tmp9_ = stmt;
			bala_code_node_emit ((BalaCodeNode*) _tmp9_, codegen);
			_bala_code_node_unref0 (stmt);
		}
		_bala_iterable_unref0 (_stmt_list);
	}
}

static void
bala_statement_list_class_init (BalaStatementListClass * klass,
                                gpointer klass_data)
{
	bala_statement_list_parent_class = g_type_class_peek_parent (klass);
	((BalaCodeNodeClass *) klass)->finalize = bala_statement_list_finalize;
	g_type_class_adjust_private_offset (klass, &BalaStatementList_private_offset);
	((BalaCodeNodeClass *) klass)->get_error_types = (void (*) (BalaCodeNode*, BalaCollection*, BalaSourceReference*)) bala_statement_list_real_get_error_types;
	((BalaCodeNodeClass *) klass)->accept = (void (*) (BalaCodeNode*, BalaCodeVisitor*)) bala_statement_list_real_accept;
	((BalaCodeNodeClass *) klass)->check = (gboolean (*) (BalaCodeNode*, BalaCodeContext*)) bala_statement_list_real_check;
	((BalaCodeNodeClass *) klass)->emit = (void (*) (BalaCodeNode*, BalaCodeGenerator*)) bala_statement_list_real_emit;
}

static void
bala_statement_list_bala_statement_interface_init (BalaStatementIface * iface,
                                                   gpointer iface_data)
{
	bala_statement_list_bala_statement_parent_iface = g_type_interface_peek_parent (iface);
}

static void
bala_statement_list_instance_init (BalaStatementList * self,
                                   gpointer klass)
{
	GEqualFunc _tmp0_;
	BalaArrayList* _tmp1_;
	self->priv = bala_statement_list_get_instance_private (self);
	_tmp0_ = g_direct_equal;
	_tmp1_ = bala_array_list_new (BALA_TYPE_STATEMENT, (GBoxedCopyFunc) bala_code_node_ref, (GDestroyNotify) bala_code_node_unref, _tmp0_);
	self->priv->list = (BalaList*) _tmp1_;
}

static void
bala_statement_list_finalize (BalaCodeNode * obj)
{
	BalaStatementList * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_STATEMENT_LIST, BalaStatementList);
	_bala_iterable_unref0 (self->priv->list);
	BALA_CODE_NODE_CLASS (bala_statement_list_parent_class)->finalize (obj);
}

static GType
bala_statement_list_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaStatementListClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_statement_list_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaStatementList), 0, (GInstanceInitFunc) bala_statement_list_instance_init, NULL };
	static const GInterfaceInfo bala_statement_info = { (GInterfaceInitFunc) bala_statement_list_bala_statement_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
	GType bala_statement_list_type_id;
	bala_statement_list_type_id = g_type_register_static (BALA_TYPE_CODE_NODE, "BalaStatementList", &g_define_type_info, 0);
	g_type_add_interface_static (bala_statement_list_type_id, BALA_TYPE_STATEMENT, &bala_statement_info);
	BalaStatementList_private_offset = g_type_add_instance_private (bala_statement_list_type_id, sizeof (BalaStatementListPrivate));
	return bala_statement_list_type_id;
}

GType
bala_statement_list_get_type (void)
{
	static volatile gsize bala_statement_list_type_id__volatile = 0;
	if (g_once_init_enter (&bala_statement_list_type_id__volatile)) {
		GType bala_statement_list_type_id;
		bala_statement_list_type_id = bala_statement_list_get_type_once ();
		g_once_init_leave (&bala_statement_list_type_id__volatile, bala_statement_list_type_id);
	}
	return bala_statement_list_type_id__volatile;
}

