/* balaswitchsection.c generated by balac, the Vala compiler
 * generated from balaswitchsection.bala, do not modify */

/* balaswitchsection.bala
 *
 * Copyright (C) 2006-2010  Jürg Billeter
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

struct _ValaSwitchSectionPrivate {
	ValaList* labels;
};

static gint ValaSwitchSection_private_offset;
static gpointer bala_switch_section_parent_class = NULL;

static void bala_switch_section_real_accept (ValaCodeNode* base,
                                      ValaCodeVisitor* visitor);
static void bala_switch_section_real_accept_children (ValaCodeNode* base,
                                               ValaCodeVisitor* visitor);
static gboolean bala_switch_section_real_check (ValaCodeNode* base,
                                         ValaCodeContext* context);
static void bala_switch_section_real_emit (ValaCodeNode* base,
                                    ValaCodeGenerator* codegen);
static void bala_switch_section_finalize (ValaCodeNode * obj);
static GType bala_switch_section_get_type_once (void);

static inline gpointer
bala_switch_section_get_instance_private (ValaSwitchSection* self)
{
	return G_STRUCT_MEMBER_P (self, ValaSwitchSection_private_offset);
}

/**
 * Creates a new switch section.
 *
 * @param source_reference reference to source code
 * @return                 newly created switch section
 */
ValaSwitchSection*
bala_switch_section_construct (GType object_type,
                               ValaSourceReference* source_reference)
{
	ValaSwitchSection* self = NULL;
	self = (ValaSwitchSection*) bala_block_construct (object_type, source_reference);
	return self;
}

ValaSwitchSection*
bala_switch_section_new (ValaSourceReference* source_reference)
{
	return bala_switch_section_construct (BALA_TYPE_SWITCH_SECTION, source_reference);
}

/**
 * Appends the specified label to the list of switch labels.
 *
 * @param label a switch label
 */
void
bala_switch_section_add_label (ValaSwitchSection* self,
                               ValaSwitchLabel* label)
{
	ValaList* _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	ValaList* _tmp5_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (label != NULL);
	_tmp0_ = self->priv->labels;
	_tmp1_ = bala_collection_get_size ((ValaCollection*) _tmp0_);
	_tmp2_ = _tmp1_;
	if (_tmp2_ == 0) {
		ValaSourceReference* _tmp3_;
		ValaSourceReference* _tmp4_;
		_tmp3_ = bala_code_node_get_source_reference ((ValaCodeNode*) label);
		_tmp4_ = _tmp3_;
		bala_code_node_set_source_reference ((ValaCodeNode*) self, _tmp4_);
	}
	_tmp5_ = self->priv->labels;
	bala_collection_add ((ValaCollection*) _tmp5_, label);
	bala_code_node_set_parent_node ((ValaCodeNode*) label, (ValaCodeNode*) self);
}

/**
 * Returns the list of switch labels.
 *
 * @return switch label list
 */
ValaList*
bala_switch_section_get_labels (ValaSwitchSection* self)
{
	ValaList* _tmp0_;
	ValaList* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->labels;
	result = _tmp0_;
	return result;
}

static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

gboolean
bala_switch_section_has_default_label (ValaSwitchSection* self)
{
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	{
		ValaList* _label_list = NULL;
		ValaList* _tmp0_;
		ValaList* _tmp1_;
		gint _label_size = 0;
		ValaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _label_index = 0;
		_tmp0_ = self->priv->labels;
		_tmp1_ = _bala_iterable_ref0 (_tmp0_);
		_label_list = _tmp1_;
		_tmp2_ = _label_list;
		_tmp3_ = bala_collection_get_size ((ValaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_label_size = _tmp4_;
		_label_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			ValaSwitchLabel* label = NULL;
			ValaList* _tmp7_;
			gpointer _tmp8_;
			ValaSwitchLabel* _tmp9_;
			ValaExpression* _tmp10_;
			ValaExpression* _tmp11_;
			_label_index = _label_index + 1;
			_tmp5_ = _label_index;
			_tmp6_ = _label_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _label_list;
			_tmp8_ = bala_list_get (_tmp7_, _label_index);
			label = (ValaSwitchLabel*) _tmp8_;
			_tmp9_ = label;
			_tmp10_ = bala_switch_label_get_expression (_tmp9_);
			_tmp11_ = _tmp10_;
			if (_tmp11_ == NULL) {
				result = TRUE;
				_bala_code_node_unref0 (label);
				_bala_iterable_unref0 (_label_list);
				return result;
			}
			_bala_code_node_unref0 (label);
		}
		_bala_iterable_unref0 (_label_list);
	}
	result = FALSE;
	return result;
}

static void
bala_switch_section_real_accept (ValaCodeNode* base,
                                 ValaCodeVisitor* visitor)
{
	ValaSwitchSection * self;
	self = (ValaSwitchSection*) base;
	g_return_if_fail (visitor != NULL);
	bala_code_visitor_visit_switch_section (visitor, self);
}

static void
bala_switch_section_real_accept_children (ValaCodeNode* base,
                                          ValaCodeVisitor* visitor)
{
	ValaSwitchSection * self;
	self = (ValaSwitchSection*) base;
	g_return_if_fail (visitor != NULL);
	{
		ValaList* _label_list = NULL;
		ValaList* _tmp0_;
		ValaList* _tmp1_;
		gint _label_size = 0;
		ValaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _label_index = 0;
		_tmp0_ = self->priv->labels;
		_tmp1_ = _bala_iterable_ref0 (_tmp0_);
		_label_list = _tmp1_;
		_tmp2_ = _label_list;
		_tmp3_ = bala_collection_get_size ((ValaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_label_size = _tmp4_;
		_label_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			ValaSwitchLabel* label = NULL;
			ValaList* _tmp7_;
			gpointer _tmp8_;
			ValaSwitchLabel* _tmp9_;
			_label_index = _label_index + 1;
			_tmp5_ = _label_index;
			_tmp6_ = _label_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _label_list;
			_tmp8_ = bala_list_get (_tmp7_, _label_index);
			label = (ValaSwitchLabel*) _tmp8_;
			_tmp9_ = label;
			bala_code_node_accept ((ValaCodeNode*) _tmp9_, visitor);
			_bala_code_node_unref0 (label);
		}
		_bala_iterable_unref0 (_label_list);
	}
	BALA_CODE_NODE_CLASS (bala_switch_section_parent_class)->accept_children ((ValaCodeNode*) G_TYPE_CHECK_INSTANCE_CAST (self, BALA_TYPE_BLOCK, ValaBlock), visitor);
}

static gboolean
bala_switch_section_real_check (ValaCodeNode* base,
                                ValaCodeContext* context)
{
	ValaSwitchSection * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	gboolean _tmp14_;
	gboolean _tmp15_;
	gboolean result = FALSE;
	self = (ValaSwitchSection*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp0_ = bala_code_node_get_checked ((ValaCodeNode*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_) {
		gboolean _tmp2_;
		gboolean _tmp3_;
		_tmp2_ = bala_code_node_get_error ((ValaCodeNode*) self);
		_tmp3_ = _tmp2_;
		result = !_tmp3_;
		return result;
	}
	{
		ValaList* _label_list = NULL;
		ValaList* _tmp4_;
		ValaList* _tmp5_;
		gint _label_size = 0;
		ValaList* _tmp6_;
		gint _tmp7_;
		gint _tmp8_;
		gint _label_index = 0;
		_tmp4_ = bala_switch_section_get_labels (self);
		_tmp5_ = _bala_iterable_ref0 (_tmp4_);
		_label_list = _tmp5_;
		_tmp6_ = _label_list;
		_tmp7_ = bala_collection_get_size ((ValaCollection*) _tmp6_);
		_tmp8_ = _tmp7_;
		_label_size = _tmp8_;
		_label_index = -1;
		while (TRUE) {
			gint _tmp9_;
			gint _tmp10_;
			ValaSwitchLabel* label = NULL;
			ValaList* _tmp11_;
			gpointer _tmp12_;
			ValaSwitchLabel* _tmp13_;
			_label_index = _label_index + 1;
			_tmp9_ = _label_index;
			_tmp10_ = _label_size;
			if (!(_tmp9_ < _tmp10_)) {
				break;
			}
			_tmp11_ = _label_list;
			_tmp12_ = bala_list_get (_tmp11_, _label_index);
			label = (ValaSwitchLabel*) _tmp12_;
			_tmp13_ = label;
			bala_code_node_check ((ValaCodeNode*) _tmp13_, context);
			_bala_code_node_unref0 (label);
		}
		_bala_iterable_unref0 (_label_list);
	}
	if (!BALA_CODE_NODE_CLASS (bala_switch_section_parent_class)->check ((ValaCodeNode*) G_TYPE_CHECK_INSTANCE_CAST (self, BALA_TYPE_BLOCK, ValaBlock), context)) {
		bala_code_node_set_error ((ValaCodeNode*) self, TRUE);
	}
	bala_code_node_set_checked ((ValaCodeNode*) self, TRUE);
	_tmp14_ = bala_code_node_get_error ((ValaCodeNode*) self);
	_tmp15_ = _tmp14_;
	result = !_tmp15_;
	return result;
}

static void
bala_switch_section_real_emit (ValaCodeNode* base,
                               ValaCodeGenerator* codegen)
{
	ValaSwitchSection * self;
	self = (ValaSwitchSection*) base;
	g_return_if_fail (codegen != NULL);
	{
		ValaList* _label_list = NULL;
		ValaList* _tmp0_;
		ValaList* _tmp1_;
		gint _label_size = 0;
		ValaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _label_index = 0;
		_tmp0_ = self->priv->labels;
		_tmp1_ = _bala_iterable_ref0 (_tmp0_);
		_label_list = _tmp1_;
		_tmp2_ = _label_list;
		_tmp3_ = bala_collection_get_size ((ValaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_label_size = _tmp4_;
		_label_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			ValaSwitchLabel* label = NULL;
			ValaList* _tmp7_;
			gpointer _tmp8_;
			ValaSwitchLabel* _tmp9_;
			_label_index = _label_index + 1;
			_tmp5_ = _label_index;
			_tmp6_ = _label_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _label_list;
			_tmp8_ = bala_list_get (_tmp7_, _label_index);
			label = (ValaSwitchLabel*) _tmp8_;
			_tmp9_ = label;
			bala_code_node_emit ((ValaCodeNode*) _tmp9_, codegen);
			_bala_code_node_unref0 (label);
		}
		_bala_iterable_unref0 (_label_list);
	}
	BALA_CODE_NODE_CLASS (bala_switch_section_parent_class)->emit ((ValaCodeNode*) G_TYPE_CHECK_INSTANCE_CAST (self, BALA_TYPE_BLOCK, ValaBlock), codegen);
}

static void
bala_switch_section_class_init (ValaSwitchSectionClass * klass,
                                gpointer klass_data)
{
	bala_switch_section_parent_class = g_type_class_peek_parent (klass);
	((ValaCodeNodeClass *) klass)->finalize = bala_switch_section_finalize;
	g_type_class_adjust_private_offset (klass, &ValaSwitchSection_private_offset);
	((ValaCodeNodeClass *) klass)->accept = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) bala_switch_section_real_accept;
	((ValaCodeNodeClass *) klass)->accept_children = (void (*) (ValaCodeNode*, ValaCodeVisitor*)) bala_switch_section_real_accept_children;
	((ValaCodeNodeClass *) klass)->check = (gboolean (*) (ValaCodeNode*, ValaCodeContext*)) bala_switch_section_real_check;
	((ValaCodeNodeClass *) klass)->emit = (void (*) (ValaCodeNode*, ValaCodeGenerator*)) bala_switch_section_real_emit;
}

static void
bala_switch_section_instance_init (ValaSwitchSection * self,
                                   gpointer klass)
{
	GEqualFunc _tmp0_;
	ValaArrayList* _tmp1_;
	self->priv = bala_switch_section_get_instance_private (self);
	_tmp0_ = g_direct_equal;
	_tmp1_ = bala_array_list_new (BALA_TYPE_SWITCH_LABEL, (GBoxedCopyFunc) bala_code_node_ref, (GDestroyNotify) bala_code_node_unref, _tmp0_);
	self->priv->labels = (ValaList*) _tmp1_;
}

static void
bala_switch_section_finalize (ValaCodeNode * obj)
{
	ValaSwitchSection * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_SWITCH_SECTION, ValaSwitchSection);
	_bala_iterable_unref0 (self->priv->labels);
	BALA_CODE_NODE_CLASS (bala_switch_section_parent_class)->finalize (obj);
}

/**
 * Represents a switch section in the source code.
 */
static GType
bala_switch_section_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (ValaSwitchSectionClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_switch_section_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ValaSwitchSection), 0, (GInstanceInitFunc) bala_switch_section_instance_init, NULL };
	GType bala_switch_section_type_id;
	bala_switch_section_type_id = g_type_register_static (BALA_TYPE_BLOCK, "ValaSwitchSection", &g_define_type_info, 0);
	ValaSwitchSection_private_offset = g_type_add_instance_private (bala_switch_section_type_id, sizeof (ValaSwitchSectionPrivate));
	return bala_switch_section_type_id;
}

GType
bala_switch_section_get_type (void)
{
	static volatile gsize bala_switch_section_type_id__volatile = 0;
	if (g_once_init_enter (&bala_switch_section_type_id__volatile)) {
		GType bala_switch_section_type_id;
		bala_switch_section_type_id = bala_switch_section_get_type_once ();
		g_once_init_leave (&bala_switch_section_type_id__volatile, bala_switch_section_type_id);
	}
	return bala_switch_section_type_id__volatile;
}
