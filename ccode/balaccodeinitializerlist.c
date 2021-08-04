/* balaccodeinitializerlist.c generated by balac, the Bala compiler
 * generated from balaccodeinitializerlist.bala, do not modify */

/* balaccodeinitializerlist.bala
 *
 * Copyright (C) 2006-2007  Jürg Billeter
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

#include "balaccode.h"
#include <balagee.h>
#include <glib-object.h>
#include <glib.h>

#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))
#define _bala_ccode_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_ccode_node_unref (var), NULL)))

struct _BalaCCodeInitializerListPrivate {
	BalaList* initializers;
};

static gint BalaCCodeInitializerList_private_offset;
static gpointer bala_ccode_initializer_list_parent_class = NULL;

static void bala_ccode_initializer_list_real_write (BalaCCodeNode* base,
                                             BalaCCodeWriter* writer);
static void bala_ccode_initializer_list_finalize (BalaCCodeNode * obj);
static GType bala_ccode_initializer_list_get_type_once (void);

static inline gpointer
bala_ccode_initializer_list_get_instance_private (BalaCCodeInitializerList* self)
{
	return G_STRUCT_MEMBER_P (self, BalaCCodeInitializerList_private_offset);
}

/**
 * Appends the specified expression to this initializer list.
 *
 * @param expr an expression
 */
void
bala_ccode_initializer_list_append (BalaCCodeInitializerList* self,
                                    BalaCCodeExpression* expr)
{
	BalaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (expr != NULL);
	_tmp0_ = self->priv->initializers;
	bala_collection_add ((BalaCollection*) _tmp0_, expr);
}

static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

static void
bala_ccode_initializer_list_real_write (BalaCCodeNode* base,
                                        BalaCCodeWriter* writer)
{
	BalaCCodeInitializerList * self;
	gboolean first = FALSE;
	self = (BalaCCodeInitializerList*) base;
	g_return_if_fail (writer != NULL);
	bala_ccode_writer_write_string (writer, "{");
	first = TRUE;
	{
		BalaList* _expr_list = NULL;
		BalaList* _tmp0_;
		BalaList* _tmp1_;
		gint _expr_size = 0;
		BalaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _expr_index = 0;
		_tmp0_ = self->priv->initializers;
		_tmp1_ = _bala_iterable_ref0 (_tmp0_);
		_expr_list = _tmp1_;
		_tmp2_ = _expr_list;
		_tmp3_ = bala_collection_get_size ((BalaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_expr_size = _tmp4_;
		_expr_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			BalaCCodeExpression* expr = NULL;
			BalaList* _tmp7_;
			gpointer _tmp8_;
			BalaCCodeExpression* _tmp9_;
			_expr_index = _expr_index + 1;
			_tmp5_ = _expr_index;
			_tmp6_ = _expr_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _expr_list;
			_tmp8_ = bala_list_get (_tmp7_, _expr_index);
			expr = (BalaCCodeExpression*) _tmp8_;
			if (!first) {
				bala_ccode_writer_write_string (writer, ", ");
			} else {
				first = FALSE;
			}
			_tmp9_ = expr;
			if (_tmp9_ != NULL) {
				BalaCCodeExpression* _tmp10_;
				_tmp10_ = expr;
				bala_ccode_node_write ((BalaCCodeNode*) _tmp10_, writer);
			}
			_bala_ccode_node_unref0 (expr);
		}
		_bala_iterable_unref0 (_expr_list);
	}
	bala_ccode_writer_write_string (writer, "}");
}

BalaCCodeInitializerList*
bala_ccode_initializer_list_construct (GType object_type)
{
	BalaCCodeInitializerList* self = NULL;
	self = (BalaCCodeInitializerList*) bala_ccode_expression_construct (object_type);
	return self;
}

BalaCCodeInitializerList*
bala_ccode_initializer_list_new (void)
{
	return bala_ccode_initializer_list_construct (BALA_TYPE_CCODE_INITIALIZER_LIST);
}

static void
bala_ccode_initializer_list_class_init (BalaCCodeInitializerListClass * klass,
                                        gpointer klass_data)
{
	bala_ccode_initializer_list_parent_class = g_type_class_peek_parent (klass);
	((BalaCCodeNodeClass *) klass)->finalize = bala_ccode_initializer_list_finalize;
	g_type_class_adjust_private_offset (klass, &BalaCCodeInitializerList_private_offset);
	((BalaCCodeNodeClass *) klass)->write = (void (*) (BalaCCodeNode*, BalaCCodeWriter*)) bala_ccode_initializer_list_real_write;
}

static void
bala_ccode_initializer_list_instance_init (BalaCCodeInitializerList * self,
                                           gpointer klass)
{
	GEqualFunc _tmp0_;
	BalaArrayList* _tmp1_;
	self->priv = bala_ccode_initializer_list_get_instance_private (self);
	_tmp0_ = g_direct_equal;
	_tmp1_ = bala_array_list_new (BALA_TYPE_CCODE_EXPRESSION, (GBoxedCopyFunc) bala_ccode_node_ref, (GDestroyNotify) bala_ccode_node_unref, _tmp0_);
	self->priv->initializers = (BalaList*) _tmp1_;
}

static void
bala_ccode_initializer_list_finalize (BalaCCodeNode * obj)
{
	BalaCCodeInitializerList * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_CCODE_INITIALIZER_LIST, BalaCCodeInitializerList);
	_bala_iterable_unref0 (self->priv->initializers);
	BALA_CCODE_NODE_CLASS (bala_ccode_initializer_list_parent_class)->finalize (obj);
}

/**
 * Represents a struct or array initializer list in the C code.
 */
static GType
bala_ccode_initializer_list_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaCCodeInitializerListClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_ccode_initializer_list_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaCCodeInitializerList), 0, (GInstanceInitFunc) bala_ccode_initializer_list_instance_init, NULL };
	GType bala_ccode_initializer_list_type_id;
	bala_ccode_initializer_list_type_id = g_type_register_static (BALA_TYPE_CCODE_EXPRESSION, "BalaCCodeInitializerList", &g_define_type_info, 0);
	BalaCCodeInitializerList_private_offset = g_type_add_instance_private (bala_ccode_initializer_list_type_id, sizeof (BalaCCodeInitializerListPrivate));
	return bala_ccode_initializer_list_type_id;
}

GType
bala_ccode_initializer_list_get_type (void)
{
	static volatile gsize bala_ccode_initializer_list_type_id__volatile = 0;
	if (g_once_init_enter (&bala_ccode_initializer_list_type_id__volatile)) {
		GType bala_ccode_initializer_list_type_id;
		bala_ccode_initializer_list_type_id = bala_ccode_initializer_list_get_type_once ();
		g_once_init_leave (&bala_ccode_initializer_list_type_id__volatile, bala_ccode_initializer_list_type_id);
	}
	return bala_ccode_initializer_list_type_id__volatile;
}

