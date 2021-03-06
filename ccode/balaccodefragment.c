/* balaccodefragment.c generated by balac, the Bala compiler
 * generated from balaccodefragment.bala, do not modify */

/* balaccodefragment.bala
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

struct _BalaCCodeFragmentPrivate {
	BalaList* children;
};

static gint BalaCCodeFragment_private_offset;
static gpointer bala_ccode_fragment_parent_class = NULL;

static void bala_ccode_fragment_real_write (BalaCCodeNode* base,
                                     BalaCCodeWriter* writer);
static void bala_ccode_fragment_real_write_declaration (BalaCCodeNode* base,
                                                 BalaCCodeWriter* writer);
static void bala_ccode_fragment_real_write_combined (BalaCCodeNode* base,
                                              BalaCCodeWriter* writer);
static void bala_ccode_fragment_finalize (BalaCCodeNode * obj);
static GType bala_ccode_fragment_get_type_once (void);

static inline gpointer
bala_ccode_fragment_get_instance_private (BalaCCodeFragment* self)
{
	return G_STRUCT_MEMBER_P (self, BalaCCodeFragment_private_offset);
}

/**
 * Appends the specified code node to this code fragment.
 *
 * @param node a C code node
 */
void
bala_ccode_fragment_append (BalaCCodeFragment* self,
                            BalaCCodeNode* node)
{
	BalaList* _tmp0_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (node != NULL);
	_tmp0_ = self->priv->children;
	bala_collection_add ((BalaCollection*) _tmp0_, node);
}

/**
 * Returns a copy of the list of children.
 *
 * @return children list
 */
static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

BalaList*
bala_ccode_fragment_get_children (BalaCCodeFragment* self)
{
	BalaList* _tmp0_;
	BalaList* _tmp1_;
	BalaList* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->children;
	_tmp1_ = _bala_iterable_ref0 (_tmp0_);
	result = _tmp1_;
	return result;
}

static void
bala_ccode_fragment_real_write (BalaCCodeNode* base,
                                BalaCCodeWriter* writer)
{
	BalaCCodeFragment * self;
	self = (BalaCCodeFragment*) base;
	g_return_if_fail (writer != NULL);
	{
		BalaList* _node_list = NULL;
		BalaList* _tmp0_;
		BalaList* _tmp1_;
		gint _node_size = 0;
		BalaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _node_index = 0;
		_tmp0_ = self->priv->children;
		_tmp1_ = _bala_iterable_ref0 (_tmp0_);
		_node_list = _tmp1_;
		_tmp2_ = _node_list;
		_tmp3_ = bala_collection_get_size ((BalaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_node_size = _tmp4_;
		_node_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			BalaCCodeNode* node = NULL;
			BalaList* _tmp7_;
			gpointer _tmp8_;
			BalaCCodeNode* _tmp9_;
			_node_index = _node_index + 1;
			_tmp5_ = _node_index;
			_tmp6_ = _node_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _node_list;
			_tmp8_ = bala_list_get (_tmp7_, _node_index);
			node = (BalaCCodeNode*) _tmp8_;
			_tmp9_ = node;
			bala_ccode_node_write (_tmp9_, writer);
			_bala_ccode_node_unref0 (node);
		}
		_bala_iterable_unref0 (_node_list);
	}
}

static void
bala_ccode_fragment_real_write_declaration (BalaCCodeNode* base,
                                            BalaCCodeWriter* writer)
{
	BalaCCodeFragment * self;
	self = (BalaCCodeFragment*) base;
	g_return_if_fail (writer != NULL);
	{
		BalaList* _node_list = NULL;
		BalaList* _tmp0_;
		BalaList* _tmp1_;
		gint _node_size = 0;
		BalaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _node_index = 0;
		_tmp0_ = self->priv->children;
		_tmp1_ = _bala_iterable_ref0 (_tmp0_);
		_node_list = _tmp1_;
		_tmp2_ = _node_list;
		_tmp3_ = bala_collection_get_size ((BalaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_node_size = _tmp4_;
		_node_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			BalaCCodeNode* node = NULL;
			BalaList* _tmp7_;
			gpointer _tmp8_;
			BalaCCodeNode* _tmp9_;
			_node_index = _node_index + 1;
			_tmp5_ = _node_index;
			_tmp6_ = _node_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _node_list;
			_tmp8_ = bala_list_get (_tmp7_, _node_index);
			node = (BalaCCodeNode*) _tmp8_;
			_tmp9_ = node;
			bala_ccode_node_write_declaration (_tmp9_, writer);
			_bala_ccode_node_unref0 (node);
		}
		_bala_iterable_unref0 (_node_list);
	}
}

static void
bala_ccode_fragment_real_write_combined (BalaCCodeNode* base,
                                         BalaCCodeWriter* writer)
{
	BalaCCodeFragment * self;
	self = (BalaCCodeFragment*) base;
	g_return_if_fail (writer != NULL);
	{
		BalaList* _node_list = NULL;
		BalaList* _tmp0_;
		BalaList* _tmp1_;
		gint _node_size = 0;
		BalaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _node_index = 0;
		_tmp0_ = self->priv->children;
		_tmp1_ = _bala_iterable_ref0 (_tmp0_);
		_node_list = _tmp1_;
		_tmp2_ = _node_list;
		_tmp3_ = bala_collection_get_size ((BalaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_node_size = _tmp4_;
		_node_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			BalaCCodeNode* node = NULL;
			BalaList* _tmp7_;
			gpointer _tmp8_;
			BalaCCodeNode* _tmp9_;
			_node_index = _node_index + 1;
			_tmp5_ = _node_index;
			_tmp6_ = _node_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _node_list;
			_tmp8_ = bala_list_get (_tmp7_, _node_index);
			node = (BalaCCodeNode*) _tmp8_;
			_tmp9_ = node;
			bala_ccode_node_write_combined (_tmp9_, writer);
			_bala_ccode_node_unref0 (node);
		}
		_bala_iterable_unref0 (_node_list);
	}
}

BalaCCodeFragment*
bala_ccode_fragment_construct (GType object_type)
{
	BalaCCodeFragment* self = NULL;
	self = (BalaCCodeFragment*) bala_ccode_node_construct (object_type);
	return self;
}

BalaCCodeFragment*
bala_ccode_fragment_new (void)
{
	return bala_ccode_fragment_construct (BALA_TYPE_CCODE_FRAGMENT);
}

static void
bala_ccode_fragment_class_init (BalaCCodeFragmentClass * klass,
                                gpointer klass_data)
{
	bala_ccode_fragment_parent_class = g_type_class_peek_parent (klass);
	((BalaCCodeNodeClass *) klass)->finalize = bala_ccode_fragment_finalize;
	g_type_class_adjust_private_offset (klass, &BalaCCodeFragment_private_offset);
	((BalaCCodeNodeClass *) klass)->write = (void (*) (BalaCCodeNode*, BalaCCodeWriter*)) bala_ccode_fragment_real_write;
	((BalaCCodeNodeClass *) klass)->write_declaration = (void (*) (BalaCCodeNode*, BalaCCodeWriter*)) bala_ccode_fragment_real_write_declaration;
	((BalaCCodeNodeClass *) klass)->write_combined = (void (*) (BalaCCodeNode*, BalaCCodeWriter*)) bala_ccode_fragment_real_write_combined;
}

static void
bala_ccode_fragment_instance_init (BalaCCodeFragment * self,
                                   gpointer klass)
{
	GEqualFunc _tmp0_;
	BalaArrayList* _tmp1_;
	self->priv = bala_ccode_fragment_get_instance_private (self);
	_tmp0_ = g_direct_equal;
	_tmp1_ = bala_array_list_new (BALA_TYPE_CCODE_NODE, (GBoxedCopyFunc) bala_ccode_node_ref, (GDestroyNotify) bala_ccode_node_unref, _tmp0_);
	self->priv->children = (BalaList*) _tmp1_;
}

static void
bala_ccode_fragment_finalize (BalaCCodeNode * obj)
{
	BalaCCodeFragment * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_CCODE_FRAGMENT, BalaCCodeFragment);
	_bala_iterable_unref0 (self->priv->children);
	BALA_CCODE_NODE_CLASS (bala_ccode_fragment_parent_class)->finalize (obj);
}

/**
 * Represents a container for C code nodes.
 */
static GType
bala_ccode_fragment_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaCCodeFragmentClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_ccode_fragment_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaCCodeFragment), 0, (GInstanceInitFunc) bala_ccode_fragment_instance_init, NULL };
	GType bala_ccode_fragment_type_id;
	bala_ccode_fragment_type_id = g_type_register_static (BALA_TYPE_CCODE_NODE, "BalaCCodeFragment", &g_define_type_info, 0);
	BalaCCodeFragment_private_offset = g_type_add_instance_private (bala_ccode_fragment_type_id, sizeof (BalaCCodeFragmentPrivate));
	return bala_ccode_fragment_type_id;
}

GType
bala_ccode_fragment_get_type (void)
{
	static volatile gsize bala_ccode_fragment_type_id__volatile = 0;
	if (g_once_init_enter (&bala_ccode_fragment_type_id__volatile)) {
		GType bala_ccode_fragment_type_id;
		bala_ccode_fragment_type_id = bala_ccode_fragment_get_type_once ();
		g_once_init_leave (&bala_ccode_fragment_type_id__volatile, bala_ccode_fragment_type_id);
	}
	return bala_ccode_fragment_type_id__volatile;
}

