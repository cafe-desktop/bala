/* balaerrordomain.c generated by balac, the Bala compiler
 * generated from balaerrordomain.bala, do not modify */

/* balaerrordomain.bala
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
#include <stdlib.h>
#include <string.h>

#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))
#define _bala_code_node_unref0(var) ((var == NULL) ? NULL : (var = (bala_code_node_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _BalaErrorDomainPrivate {
	BalaList* codes;
	BalaList* methods;
};

static gint BalaErrorDomain_private_offset;
static gpointer bala_error_domain_parent_class = NULL;

static void bala_error_domain_real_add_method (BalaSymbol* base,
                                        BalaMethod* m);
static void bala_error_domain_real_accept (BalaCodeNode* base,
                                    BalaCodeVisitor* visitor);
static void bala_error_domain_real_accept_children (BalaCodeNode* base,
                                             BalaCodeVisitor* visitor);
static gboolean bala_error_domain_real_is_reference_type (BalaTypeSymbol* base);
static gboolean bala_error_domain_real_check (BalaCodeNode* base,
                                       BalaCodeContext* context);
static void bala_error_domain_finalize (BalaCodeNode * obj);
static GType bala_error_domain_get_type_once (void);

static inline gpointer
bala_error_domain_get_instance_private (BalaErrorDomain* self)
{
	return G_STRUCT_MEMBER_P (self, BalaErrorDomain_private_offset);
}

/**
 * Creates a new error domain.
 *
 * @param name             type name
 * @param source_reference reference to source code
 * @return                 newly created error domain
 */
BalaErrorDomain*
bala_error_domain_construct (GType object_type,
                             const gchar* name,
                             BalaSourceReference* source_reference,
                             BalaComment* comment)
{
	BalaErrorDomain* self = NULL;
	g_return_val_if_fail (name != NULL, NULL);
	self = (BalaErrorDomain*) bala_typesymbol_construct (object_type, name, source_reference, comment);
	return self;
}

BalaErrorDomain*
bala_error_domain_new (const gchar* name,
                       BalaSourceReference* source_reference,
                       BalaComment* comment)
{
	return bala_error_domain_construct (BALA_TYPE_ERROR_DOMAIN, name, source_reference, comment);
}

/**
 * Appends the specified code to the list of error codes.
 *
 * @param ecode an error code
 */
void
bala_error_domain_add_code (BalaErrorDomain* self,
                            BalaErrorCode* ecode)
{
	BalaList* _tmp0_;
	BalaScope* _tmp1_;
	BalaScope* _tmp2_;
	const gchar* _tmp3_;
	const gchar* _tmp4_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (ecode != NULL);
	_tmp0_ = self->priv->codes;
	bala_collection_add ((BalaCollection*) _tmp0_, ecode);
	_tmp1_ = bala_symbol_get_scope ((BalaSymbol*) self);
	_tmp2_ = _tmp1_;
	_tmp3_ = bala_symbol_get_name ((BalaSymbol*) ecode);
	_tmp4_ = _tmp3_;
	bala_scope_add (_tmp2_, _tmp4_, (BalaSymbol*) ecode);
}

/**
 * Adds the specified method as a member to this error domain.
 *
 * @param m a method
 */
static void
bala_error_domain_real_add_method (BalaSymbol* base,
                                   BalaMethod* m)
{
	BalaErrorDomain * self;
	BalaMemberBinding _tmp2_;
	BalaMemberBinding _tmp3_;
	BalaList* _tmp18_;
	BalaScope* _tmp19_;
	BalaScope* _tmp20_;
	const gchar* _tmp21_;
	const gchar* _tmp22_;
	self = (BalaErrorDomain*) base;
	g_return_if_fail (m != NULL);
	if (BALA_IS_CREATION_METHOD (m)) {
		BalaSourceReference* _tmp0_;
		BalaSourceReference* _tmp1_;
		_tmp0_ = bala_code_node_get_source_reference ((BalaCodeNode*) m);
		_tmp1_ = _tmp0_;
		bala_report_error (_tmp1_, "construction methods may only be declared within classes and structs");
		bala_code_node_set_error ((BalaCodeNode*) m, TRUE);
		return;
	}
	_tmp2_ = bala_method_get_binding (m);
	_tmp3_ = _tmp2_;
	if (_tmp3_ == BALA_MEMBER_BINDING_INSTANCE) {
		BalaErrorType* _tmp4_;
		BalaErrorType* _tmp5_;
		BalaSourceReference* _tmp6_;
		BalaSourceReference* _tmp7_;
		BalaParameter* _tmp8_;
		BalaParameter* _tmp9_;
		BalaScope* _tmp10_;
		BalaScope* _tmp11_;
		BalaParameter* _tmp12_;
		BalaParameter* _tmp13_;
		const gchar* _tmp14_;
		const gchar* _tmp15_;
		BalaParameter* _tmp16_;
		BalaParameter* _tmp17_;
		_tmp4_ = bala_error_type_new (self, NULL, NULL);
		_tmp5_ = _tmp4_;
		_tmp6_ = bala_code_node_get_source_reference ((BalaCodeNode*) m);
		_tmp7_ = _tmp6_;
		_tmp8_ = bala_parameter_new ("this", (BalaDataType*) _tmp5_, _tmp7_);
		_tmp9_ = _tmp8_;
		bala_method_set_this_parameter (m, _tmp9_);
		_bala_code_node_unref0 (_tmp9_);
		_bala_code_node_unref0 (_tmp5_);
		_tmp10_ = bala_symbol_get_scope ((BalaSymbol*) m);
		_tmp11_ = _tmp10_;
		_tmp12_ = bala_method_get_this_parameter (m);
		_tmp13_ = _tmp12_;
		_tmp14_ = bala_symbol_get_name ((BalaSymbol*) _tmp13_);
		_tmp15_ = _tmp14_;
		_tmp16_ = bala_method_get_this_parameter (m);
		_tmp17_ = _tmp16_;
		bala_scope_add (_tmp11_, _tmp15_, (BalaSymbol*) _tmp17_);
	}
	_tmp18_ = self->priv->methods;
	bala_collection_add ((BalaCollection*) _tmp18_, m);
	_tmp19_ = bala_symbol_get_scope ((BalaSymbol*) self);
	_tmp20_ = _tmp19_;
	_tmp21_ = bala_symbol_get_name ((BalaSymbol*) m);
	_tmp22_ = _tmp21_;
	bala_scope_add (_tmp20_, _tmp22_, (BalaSymbol*) m);
}

/**
 * Returns the list of error codes.
 *
 * @return list of error codes
 */
BalaList*
bala_error_domain_get_codes (BalaErrorDomain* self)
{
	BalaList* _tmp0_;
	BalaList* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->codes;
	result = _tmp0_;
	return result;
}

/**
 * Returns the list of methods.
 *
 * @return list of methods
 */
BalaList*
bala_error_domain_get_methods (BalaErrorDomain* self)
{
	BalaList* _tmp0_;
	BalaList* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->methods;
	result = _tmp0_;
	return result;
}

static void
bala_error_domain_real_accept (BalaCodeNode* base,
                               BalaCodeVisitor* visitor)
{
	BalaErrorDomain * self;
	self = (BalaErrorDomain*) base;
	g_return_if_fail (visitor != NULL);
	bala_code_visitor_visit_error_domain (visitor, self);
}

static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

static void
bala_error_domain_real_accept_children (BalaCodeNode* base,
                                        BalaCodeVisitor* visitor)
{
	BalaErrorDomain * self;
	self = (BalaErrorDomain*) base;
	g_return_if_fail (visitor != NULL);
	{
		BalaList* _ecode_list = NULL;
		BalaList* _tmp0_;
		BalaList* _tmp1_;
		gint _ecode_size = 0;
		BalaList* _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _ecode_index = 0;
		_tmp0_ = self->priv->codes;
		_tmp1_ = _bala_iterable_ref0 (_tmp0_);
		_ecode_list = _tmp1_;
		_tmp2_ = _ecode_list;
		_tmp3_ = bala_collection_get_size ((BalaCollection*) _tmp2_);
		_tmp4_ = _tmp3_;
		_ecode_size = _tmp4_;
		_ecode_index = -1;
		while (TRUE) {
			gint _tmp5_;
			gint _tmp6_;
			BalaErrorCode* ecode = NULL;
			BalaList* _tmp7_;
			gpointer _tmp8_;
			BalaErrorCode* _tmp9_;
			_ecode_index = _ecode_index + 1;
			_tmp5_ = _ecode_index;
			_tmp6_ = _ecode_size;
			if (!(_tmp5_ < _tmp6_)) {
				break;
			}
			_tmp7_ = _ecode_list;
			_tmp8_ = bala_list_get (_tmp7_, _ecode_index);
			ecode = (BalaErrorCode*) _tmp8_;
			_tmp9_ = ecode;
			bala_code_node_accept ((BalaCodeNode*) _tmp9_, visitor);
			_bala_code_node_unref0 (ecode);
		}
		_bala_iterable_unref0 (_ecode_list);
	}
	{
		BalaList* _m_list = NULL;
		BalaList* _tmp10_;
		BalaList* _tmp11_;
		gint _m_size = 0;
		BalaList* _tmp12_;
		gint _tmp13_;
		gint _tmp14_;
		gint _m_index = 0;
		_tmp10_ = self->priv->methods;
		_tmp11_ = _bala_iterable_ref0 (_tmp10_);
		_m_list = _tmp11_;
		_tmp12_ = _m_list;
		_tmp13_ = bala_collection_get_size ((BalaCollection*) _tmp12_);
		_tmp14_ = _tmp13_;
		_m_size = _tmp14_;
		_m_index = -1;
		while (TRUE) {
			gint _tmp15_;
			gint _tmp16_;
			BalaMethod* m = NULL;
			BalaList* _tmp17_;
			gpointer _tmp18_;
			BalaMethod* _tmp19_;
			_m_index = _m_index + 1;
			_tmp15_ = _m_index;
			_tmp16_ = _m_size;
			if (!(_tmp15_ < _tmp16_)) {
				break;
			}
			_tmp17_ = _m_list;
			_tmp18_ = bala_list_get (_tmp17_, _m_index);
			m = (BalaMethod*) _tmp18_;
			_tmp19_ = m;
			bala_code_node_accept ((BalaCodeNode*) _tmp19_, visitor);
			_bala_code_node_unref0 (m);
		}
		_bala_iterable_unref0 (_m_list);
	}
}

static gboolean
bala_error_domain_real_is_reference_type (BalaTypeSymbol* base)
{
	BalaErrorDomain * self;
	gboolean result = FALSE;
	self = (BalaErrorDomain*) base;
	result = FALSE;
	return result;
}

static gboolean
bala_error_domain_real_check (BalaCodeNode* base,
                              BalaCodeContext* context)
{
	BalaErrorDomain * self;
	gboolean _tmp0_;
	gboolean _tmp1_;
	BalaList* _tmp4_;
	gint _tmp5_;
	gint _tmp6_;
	gboolean _tmp44_;
	gboolean _tmp45_;
	gboolean result = FALSE;
	self = (BalaErrorDomain*) base;
	g_return_val_if_fail (context != NULL, FALSE);
	_tmp0_ = bala_code_node_get_checked ((BalaCodeNode*) self);
	_tmp1_ = _tmp0_;
	if (_tmp1_) {
		gboolean _tmp2_;
		gboolean _tmp3_;
		_tmp2_ = bala_code_node_get_error ((BalaCodeNode*) self);
		_tmp3_ = _tmp2_;
		result = !_tmp3_;
		return result;
	}
	bala_code_node_set_checked ((BalaCodeNode*) self, TRUE);
	_tmp4_ = self->priv->codes;
	_tmp5_ = bala_collection_get_size ((BalaCollection*) _tmp4_);
	_tmp6_ = _tmp5_;
	if (_tmp6_ <= 0) {
		BalaSourceReference* _tmp7_;
		BalaSourceReference* _tmp8_;
		gchar* _tmp9_;
		gchar* _tmp10_;
		gchar* _tmp11_;
		gchar* _tmp12_;
		_tmp7_ = bala_code_node_get_source_reference ((BalaCodeNode*) self);
		_tmp8_ = _tmp7_;
		_tmp9_ = bala_symbol_get_full_name ((BalaSymbol*) self);
		_tmp10_ = _tmp9_;
		_tmp11_ = g_strdup_printf ("Error domain `%s' requires at least one code", _tmp10_);
		_tmp12_ = _tmp11_;
		bala_report_error (_tmp8_, _tmp12_);
		_g_free0 (_tmp12_);
		_g_free0 (_tmp10_);
		bala_code_node_set_error ((BalaCodeNode*) self, TRUE);
		result = FALSE;
		return result;
	}
	{
		BalaList* _ecode_list = NULL;
		BalaList* _tmp13_;
		BalaList* _tmp14_;
		gint _ecode_size = 0;
		BalaList* _tmp15_;
		gint _tmp16_;
		gint _tmp17_;
		gint _ecode_index = 0;
		_tmp13_ = self->priv->codes;
		_tmp14_ = _bala_iterable_ref0 (_tmp13_);
		_ecode_list = _tmp14_;
		_tmp15_ = _ecode_list;
		_tmp16_ = bala_collection_get_size ((BalaCollection*) _tmp15_);
		_tmp17_ = _tmp16_;
		_ecode_size = _tmp17_;
		_ecode_index = -1;
		while (TRUE) {
			gint _tmp18_;
			gint _tmp19_;
			BalaErrorCode* ecode = NULL;
			BalaList* _tmp20_;
			gpointer _tmp21_;
			BalaErrorCode* _tmp22_;
			_ecode_index = _ecode_index + 1;
			_tmp18_ = _ecode_index;
			_tmp19_ = _ecode_size;
			if (!(_tmp18_ < _tmp19_)) {
				break;
			}
			_tmp20_ = _ecode_list;
			_tmp21_ = bala_list_get (_tmp20_, _ecode_index);
			ecode = (BalaErrorCode*) _tmp21_;
			_tmp22_ = ecode;
			bala_code_node_check ((BalaCodeNode*) _tmp22_, context);
			_bala_code_node_unref0 (ecode);
		}
		_bala_iterable_unref0 (_ecode_list);
	}
	{
		BalaList* _m_list = NULL;
		BalaList* _tmp23_;
		BalaList* _tmp24_;
		gint _m_size = 0;
		BalaList* _tmp25_;
		gint _tmp26_;
		gint _tmp27_;
		gint _m_index = 0;
		_tmp23_ = self->priv->methods;
		_tmp24_ = _bala_iterable_ref0 (_tmp23_);
		_m_list = _tmp24_;
		_tmp25_ = _m_list;
		_tmp26_ = bala_collection_get_size ((BalaCollection*) _tmp25_);
		_tmp27_ = _tmp26_;
		_m_size = _tmp27_;
		_m_index = -1;
		while (TRUE) {
			gint _tmp28_;
			gint _tmp29_;
			BalaMethod* m = NULL;
			BalaList* _tmp30_;
			gpointer _tmp31_;
			BalaMethod* _tmp32_;
			BalaMemberBinding _tmp33_;
			BalaMemberBinding _tmp34_;
			BalaMethod* _tmp43_;
			_m_index = _m_index + 1;
			_tmp28_ = _m_index;
			_tmp29_ = _m_size;
			if (!(_tmp28_ < _tmp29_)) {
				break;
			}
			_tmp30_ = _m_list;
			_tmp31_ = bala_list_get (_tmp30_, _m_index);
			m = (BalaMethod*) _tmp31_;
			_tmp32_ = m;
			_tmp33_ = bala_method_get_binding (_tmp32_);
			_tmp34_ = _tmp33_;
			if (_tmp34_ == BALA_MEMBER_BINDING_INSTANCE) {
				gboolean _tmp35_;
				gboolean _tmp36_;
				_tmp35_ = bala_symbol_get_external_package ((BalaSymbol*) self);
				_tmp36_ = _tmp35_;
				if (_tmp36_) {
					BalaMethod* _tmp37_;
					BalaSourceReference* _tmp38_;
					BalaSourceReference* _tmp39_;
					_tmp37_ = m;
					_tmp38_ = bala_code_node_get_source_reference ((BalaCodeNode*) _tmp37_);
					_tmp39_ = _tmp38_;
					bala_report_warning (_tmp39_, "Instance methods are not supported in error domains yet");
				} else {
					BalaMethod* _tmp40_;
					BalaSourceReference* _tmp41_;
					BalaSourceReference* _tmp42_;
					_tmp40_ = m;
					_tmp41_ = bala_code_node_get_source_reference ((BalaCodeNode*) _tmp40_);
					_tmp42_ = _tmp41_;
					bala_report_error (_tmp42_, "Instance methods are not supported in error domains yet");
				}
				bala_code_node_set_error ((BalaCodeNode*) self, TRUE);
			}
			_tmp43_ = m;
			bala_code_node_check ((BalaCodeNode*) _tmp43_, context);
			_bala_code_node_unref0 (m);
		}
		_bala_iterable_unref0 (_m_list);
	}
	_tmp44_ = bala_code_node_get_error ((BalaCodeNode*) self);
	_tmp45_ = _tmp44_;
	result = !_tmp45_;
	return result;
}

static void
bala_error_domain_class_init (BalaErrorDomainClass * klass,
                              gpointer klass_data)
{
	bala_error_domain_parent_class = g_type_class_peek_parent (klass);
	((BalaCodeNodeClass *) klass)->finalize = bala_error_domain_finalize;
	g_type_class_adjust_private_offset (klass, &BalaErrorDomain_private_offset);
	((BalaSymbolClass *) klass)->add_method = (void (*) (BalaSymbol*, BalaMethod*)) bala_error_domain_real_add_method;
	((BalaCodeNodeClass *) klass)->accept = (void (*) (BalaCodeNode*, BalaCodeVisitor*)) bala_error_domain_real_accept;
	((BalaCodeNodeClass *) klass)->accept_children = (void (*) (BalaCodeNode*, BalaCodeVisitor*)) bala_error_domain_real_accept_children;
	((BalaTypeSymbolClass *) klass)->is_reference_type = (gboolean (*) (BalaTypeSymbol*)) bala_error_domain_real_is_reference_type;
	((BalaCodeNodeClass *) klass)->check = (gboolean (*) (BalaCodeNode*, BalaCodeContext*)) bala_error_domain_real_check;
}

static void
bala_error_domain_instance_init (BalaErrorDomain * self,
                                 gpointer klass)
{
	GEqualFunc _tmp0_;
	BalaArrayList* _tmp1_;
	GEqualFunc _tmp2_;
	BalaArrayList* _tmp3_;
	self->priv = bala_error_domain_get_instance_private (self);
	_tmp0_ = g_direct_equal;
	_tmp1_ = bala_array_list_new (BALA_TYPE_ERROR_CODE, (GBoxedCopyFunc) bala_code_node_ref, (GDestroyNotify) bala_code_node_unref, _tmp0_);
	self->priv->codes = (BalaList*) _tmp1_;
	_tmp2_ = g_direct_equal;
	_tmp3_ = bala_array_list_new (BALA_TYPE_METHOD, (GBoxedCopyFunc) bala_code_node_ref, (GDestroyNotify) bala_code_node_unref, _tmp2_);
	self->priv->methods = (BalaList*) _tmp3_;
}

static void
bala_error_domain_finalize (BalaCodeNode * obj)
{
	BalaErrorDomain * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_ERROR_DOMAIN, BalaErrorDomain);
	_bala_iterable_unref0 (self->priv->codes);
	_bala_iterable_unref0 (self->priv->methods);
	BALA_CODE_NODE_CLASS (bala_error_domain_parent_class)->finalize (obj);
}

/**
 * Represents an error domain declaration in the source code.
 */
static GType
bala_error_domain_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BalaErrorDomainClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_error_domain_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaErrorDomain), 0, (GInstanceInitFunc) bala_error_domain_instance_init, NULL };
	GType bala_error_domain_type_id;
	bala_error_domain_type_id = g_type_register_static (BALA_TYPE_TYPESYMBOL, "BalaErrorDomain", &g_define_type_info, 0);
	BalaErrorDomain_private_offset = g_type_add_instance_private (bala_error_domain_type_id, sizeof (BalaErrorDomainPrivate));
	return bala_error_domain_type_id;
}

GType
bala_error_domain_get_type (void)
{
	static volatile gsize bala_error_domain_type_id__volatile = 0;
	if (g_once_init_enter (&bala_error_domain_type_id__volatile)) {
		GType bala_error_domain_type_id;
		bala_error_domain_type_id = bala_error_domain_get_type_once ();
		g_once_init_leave (&bala_error_domain_type_id__volatile, bala_error_domain_type_id);
	}
	return bala_error_domain_type_id__volatile;
}

