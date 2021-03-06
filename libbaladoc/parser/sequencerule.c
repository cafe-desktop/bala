/* sequencerule.c generated by balac, the Bala compiler
 * generated from sequencerule.bala, do not modify */

/* sequencerule.bala
 *
 * Copyright (C) 2008-2009 Florian Brosch, Didier Villevalois
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 * Author:
 * 	Didier 'Ptitjes Villevalois <ptitjes@free.fr>
 */

#include "baladoc.h"
#include <glib-object.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>

#define BALADOC_TYPE_SEQUENCE_RULE (baladoc_sequence_rule_get_type ())
#define BALADOC_SEQUENCE_RULE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), BALADOC_TYPE_SEQUENCE_RULE, BaladocSequenceRule))
#define BALADOC_SEQUENCE_RULE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), BALADOC_TYPE_SEQUENCE_RULE, BaladocSequenceRuleClass))
#define BALADOC_IS_SEQUENCE_RULE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BALADOC_TYPE_SEQUENCE_RULE))
#define BALADOC_IS_SEQUENCE_RULE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BALADOC_TYPE_SEQUENCE_RULE))
#define BALADOC_SEQUENCE_RULE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), BALADOC_TYPE_SEQUENCE_RULE, BaladocSequenceRuleClass))

typedef struct _BaladocSequenceRule BaladocSequenceRule;
typedef struct _BaladocSequenceRuleClass BaladocSequenceRuleClass;
typedef struct _BaladocSequenceRulePrivate BaladocSequenceRulePrivate;
enum  {
	BALADOC_SEQUENCE_RULE_0_PROPERTY,
	BALADOC_SEQUENCE_RULE_NUM_PROPERTIES
};
static GParamSpec* baladoc_sequence_rule_properties[BALADOC_SEQUENCE_RULE_NUM_PROPERTIES];

#define BALADOC_SEQUENCE_RULE_TYPE_STATE (baladoc_sequence_rule_state_get_type ())
#define BALADOC_SEQUENCE_RULE_STATE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), BALADOC_SEQUENCE_RULE_TYPE_STATE, BaladocSequenceRuleState))
#define BALADOC_SEQUENCE_RULE_STATE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), BALADOC_SEQUENCE_RULE_TYPE_STATE, BaladocSequenceRuleStateClass))
#define BALADOC_SEQUENCE_RULE_IS_STATE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BALADOC_SEQUENCE_RULE_TYPE_STATE))
#define BALADOC_SEQUENCE_RULE_IS_STATE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), BALADOC_SEQUENCE_RULE_TYPE_STATE))
#define BALADOC_SEQUENCE_RULE_STATE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), BALADOC_SEQUENCE_RULE_TYPE_STATE, BaladocSequenceRuleStateClass))

typedef struct _BaladocSequenceRuleState BaladocSequenceRuleState;
typedef struct _BaladocSequenceRuleStateClass BaladocSequenceRuleStateClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _BaladocSequenceRuleStatePrivate BaladocSequenceRuleStatePrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
enum  {
	BALADOC_SEQUENCE_RULE_STATE_0_PROPERTY,
	BALADOC_SEQUENCE_RULE_STATE_NUM_PROPERTIES
};
static GParamSpec* baladoc_sequence_rule_state_properties[BALADOC_SEQUENCE_RULE_STATE_NUM_PROPERTIES];

struct _BaladocSequenceRule {
	BaladocRule parent_instance;
	BaladocSequenceRulePrivate * priv;
};

struct _BaladocSequenceRuleClass {
	BaladocRuleClass parent_class;
};

struct _BaladocSequenceRulePrivate {
	GObject** _scheme;
	gint _scheme_length1;
	gint __scheme_size_;
};

struct _BaladocSequenceRuleState {
	GObject parent_instance;
	gint index;
	BaladocSequenceRuleStatePrivate * priv;
};

struct _BaladocSequenceRuleStateClass {
	GObjectClass parent_class;
};

static gint BaladocSequenceRule_private_offset;
static gpointer baladoc_sequence_rule_parent_class = NULL;
static gpointer baladoc_sequence_rule_state_parent_class = NULL;

G_GNUC_INTERNAL GType baladoc_sequence_rule_get_type (void) G_GNUC_CONST G_GNUC_UNUSED;
G_GNUC_INTERNAL BaladocSequenceRule* baladoc_sequence_rule_new (GObject** scheme,
                                                gint scheme_length1);
G_GNUC_INTERNAL BaladocSequenceRule* baladoc_sequence_rule_construct (GType object_type,
                                                      GObject** scheme,
                                                      gint scheme_length1);
static GObject** _bala_array_dup3 (GObject** self,
                            gint length);
static gboolean baladoc_sequence_rule_real_is_optional (BaladocRule* base);
static gboolean baladoc_sequence_rule_real_starts_with_token (BaladocRule* base,
                                                       BaladocToken* token);
static gboolean baladoc_sequence_rule_test_token (BaladocSequenceRule* self,
                                           gint from_index,
                                           BaladocToken* token);
static gboolean baladoc_sequence_rule_test_reduce (BaladocSequenceRule* self,
                                            gint from_index,
                                            BaladocToken* token);
static gboolean baladoc_sequence_rule_real_accept_token (BaladocRule* base,
                                                  BaladocToken* token,
                                                  BaladocParserCallback* parser,
                                                  BaladocRuleForward forward,
                                                  GError** error);
static GType baladoc_sequence_rule_state_get_type (void) G_GNUC_CONST G_GNUC_UNUSED;
static BaladocSequenceRuleState* baladoc_sequence_rule_state_new (void);
static BaladocSequenceRuleState* baladoc_sequence_rule_state_construct (GType object_type);
static gboolean baladoc_sequence_rule_real_would_accept_token (BaladocRule* base,
                                                        BaladocToken* token,
                                                        GObject* rule_state);
static gboolean baladoc_sequence_rule_real_would_reduce (BaladocRule* base,
                                                  BaladocToken* token,
                                                  GObject* rule_state);
static gchar* baladoc_sequence_rule_real_to_string (BaladocRule* base,
                                             GObject* rule_state);
static void baladoc_sequence_rule_state_finalize (GObject * obj);
static GType baladoc_sequence_rule_state_get_type_once (void);
static void baladoc_sequence_rule_finalize (GObject * obj);
static GType baladoc_sequence_rule_get_type_once (void);
static void _bala_array_destroy (gpointer array,
                          gint array_length,
                          GDestroyNotify destroy_func);
static void _bala_array_free (gpointer array,
                       gint array_length,
                       GDestroyNotify destroy_func);

static inline gpointer
baladoc_sequence_rule_get_instance_private (BaladocSequenceRule* self)
{
	return G_STRUCT_MEMBER_P (self, BaladocSequenceRule_private_offset);
}

static gpointer
_g_object_ref0 (gpointer self)
{
	return self ? g_object_ref (self) : NULL;
}

static GObject**
_bala_array_dup3 (GObject** self,
                  gint length)
{
	if (length >= 0) {
		GObject** result;
		gint i;
		result = g_new0 (GObject*, length + 1);
		for (i = 0; i < length; i++) {
			GObject* _tmp0_;
			_tmp0_ = _g_object_ref0 (self[i]);
			result[i] = _tmp0_;
		}
		return result;
	}
	return NULL;
}

G_GNUC_INTERNAL BaladocSequenceRule*
baladoc_sequence_rule_construct (GType object_type,
                                 GObject** scheme,
                                 gint scheme_length1)
{
	BaladocSequenceRule * self = NULL;
	GObject** _tmp0_;
	gint _tmp0__length1;
	self = (BaladocSequenceRule*) baladoc_rule_construct (object_type);
	_tmp0_ = (scheme != NULL) ? _bala_array_dup3 (scheme, scheme_length1) : ((gpointer) scheme);
	_tmp0__length1 = scheme_length1;
	self->priv->_scheme = (_bala_array_free (self->priv->_scheme, self->priv->_scheme_length1, (GDestroyNotify) g_object_unref), NULL);
	self->priv->_scheme = _tmp0_;
	self->priv->_scheme_length1 = _tmp0__length1;
	self->priv->__scheme_size_ = self->priv->_scheme_length1;
	return self;
}

G_GNUC_INTERNAL BaladocSequenceRule*
baladoc_sequence_rule_new (GObject** scheme,
                           gint scheme_length1)
{
	return baladoc_sequence_rule_construct (BALADOC_TYPE_SEQUENCE_RULE, scheme, scheme_length1);
}

static gboolean
baladoc_sequence_rule_real_is_optional (BaladocRule* base)
{
	BaladocSequenceRule * self;
	gboolean result = FALSE;
	self = (BaladocSequenceRule*) base;
	result = FALSE;
	return result;
}

static gboolean
baladoc_sequence_rule_real_starts_with_token (BaladocRule* base,
                                              BaladocToken* token)
{
	BaladocSequenceRule * self;
	gboolean result = FALSE;
	self = (BaladocSequenceRule*) base;
	g_return_val_if_fail (token != NULL, FALSE);
	result = baladoc_sequence_rule_test_token (self, 0, token);
	return result;
}

static gboolean
baladoc_sequence_rule_test_token (BaladocSequenceRule* self,
                                  gint from_index,
                                  BaladocToken* token)
{
	gint i = 0;
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (token != NULL, FALSE);
	i = from_index;
	while (TRUE) {
		GObject** _tmp0_;
		gint _tmp0__length1;
		GObject** _tmp1_;
		gint _tmp1__length1;
		GObject* _tmp2_;
		GObject** _tmp3_;
		gint _tmp3__length1;
		GObject* _tmp4_;
		gint _tmp5_;
		_tmp0_ = self->priv->_scheme;
		_tmp0__length1 = self->priv->_scheme_length1;
		if (!(i < _tmp0__length1)) {
			break;
		}
		_tmp1_ = self->priv->_scheme;
		_tmp1__length1 = self->priv->_scheme_length1;
		_tmp2_ = _tmp1_[i];
		if (baladoc_rule_has_start_token ((BaladocRule*) self, _tmp2_, token)) {
			result = TRUE;
			return result;
		}
		_tmp3_ = self->priv->_scheme;
		_tmp3__length1 = self->priv->_scheme_length1;
		_tmp4_ = _tmp3_[i];
		if (!baladoc_rule_is_optional_rule ((BaladocRule*) self, _tmp4_)) {
			break;
		}
		_tmp5_ = i;
		i = _tmp5_ + 1;
	}
	result = FALSE;
	return result;
}

static gboolean
baladoc_sequence_rule_test_reduce (BaladocSequenceRule* self,
                                   gint from_index,
                                   BaladocToken* token)
{
	gint i = 0;
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (token != NULL, FALSE);
	i = from_index;
	while (TRUE) {
		GObject** _tmp0_;
		gint _tmp0__length1;
		GObject** _tmp1_;
		gint _tmp1__length1;
		GObject* _tmp2_;
		gint _tmp3_;
		_tmp0_ = self->priv->_scheme;
		_tmp0__length1 = self->priv->_scheme_length1;
		if (!(i < _tmp0__length1)) {
			break;
		}
		_tmp1_ = self->priv->_scheme;
		_tmp1__length1 = self->priv->_scheme_length1;
		_tmp2_ = _tmp1_[i];
		if (!baladoc_rule_is_optional_rule ((BaladocRule*) self, _tmp2_)) {
			result = FALSE;
			return result;
		}
		_tmp3_ = i;
		i = _tmp3_ + 1;
	}
	result = TRUE;
	return result;
}

static gboolean
baladoc_sequence_rule_real_accept_token (BaladocRule* base,
                                         BaladocToken* token,
                                         BaladocParserCallback* parser,
                                         BaladocRuleForward forward,
                                         GError** error)
{
	BaladocSequenceRule * self;
	BaladocSequenceRuleState* state = NULL;
	GObject* _tmp0_;
	BaladocSequenceRuleState* _tmp1_;
	BaladocSequenceRuleState* _tmp2_;
	BaladocSequenceRuleState* _tmp5_;
	GObject* scheme_element = NULL;
	gboolean handled = FALSE;
	BaladocSequenceRuleState* _tmp33_;
	GObject** _tmp34_;
	gint _tmp34__length1;
	GObject* _tmp37_;
	GError* _inner_error0_ = NULL;
	gboolean result = FALSE;
	self = (BaladocSequenceRule*) base;
	g_return_val_if_fail (token != NULL, FALSE);
	g_return_val_if_fail (parser != NULL, FALSE);
	_tmp0_ = baladoc_parser_callback_get_rule_state (parser);
	_tmp1_ = BALADOC_SEQUENCE_RULE_IS_STATE (_tmp0_) ? ((BaladocSequenceRuleState*) _tmp0_) : NULL;
	if (_tmp1_ == NULL) {
		_g_object_unref0 (_tmp0_);
	}
	state = _tmp1_;
	_tmp2_ = state;
	if (_tmp2_ == NULL) {
		BaladocSequenceRuleState* _tmp3_;
		BaladocSequenceRuleState* _tmp4_;
		_tmp3_ = baladoc_sequence_rule_state_new ();
		_g_object_unref0 (state);
		state = _tmp3_;
		_tmp4_ = state;
		baladoc_parser_callback_set_rule_state (parser, (GObject*) _tmp4_);
	}
	_tmp5_ = state;
	if (_tmp5_->index == 0) {
		baladoc_rule_do_start ((BaladocRule*) self, parser, &_inner_error0_);
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			if (_inner_error0_->domain == BALADOC_PARSER_ERROR) {
				gboolean _tmp6_ = FALSE;
				g_propagate_error (error, _inner_error0_);
				_g_object_unref0 (state);
				return _tmp6_;
			} else {
				gboolean _tmp7_ = FALSE;
				_g_object_unref0 (state);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
				g_clear_error (&_inner_error0_);
				return _tmp7_;
			}
		}
	} else {
		BaladocSequenceRuleState* _tmp8_;
		GObject** _tmp9_;
		gint _tmp9__length1;
		_tmp8_ = state;
		_tmp9_ = self->priv->_scheme;
		_tmp9__length1 = self->priv->_scheme_length1;
		if (_tmp8_->index == _tmp9__length1) {
			baladoc_rule_do_reduce ((BaladocRule*) self, parser, &_inner_error0_);
			if (G_UNLIKELY (_inner_error0_ != NULL)) {
				if (_inner_error0_->domain == BALADOC_PARSER_ERROR) {
					gboolean _tmp10_ = FALSE;
					g_propagate_error (error, _inner_error0_);
					_g_object_unref0 (state);
					return _tmp10_;
				} else {
					gboolean _tmp11_ = FALSE;
					_g_object_unref0 (state);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
					g_clear_error (&_inner_error0_);
					return _tmp11_;
				}
			}
			result = FALSE;
			_g_object_unref0 (state);
			return result;
		}
	}
	scheme_element = NULL;
	{
		gboolean _tmp12_ = FALSE;
		_tmp12_ = TRUE;
		while (TRUE) {
			GObject** _tmp15_;
			gint _tmp15__length1;
			BaladocSequenceRuleState* _tmp16_;
			GObject* _tmp17_;
			GObject* _tmp18_;
			gboolean _tmp19_ = FALSE;
			GObject* _tmp20_;
			gboolean _tmp21_ = FALSE;
			gboolean _tmp22_;
			GObject* _tmp27_;
			BaladocSequenceRuleState* _tmp31_;
			gint _tmp32_;
			if (!_tmp12_) {
				BaladocSequenceRuleState* _tmp13_;
				GObject** _tmp14_;
				gint _tmp14__length1;
				_tmp13_ = state;
				_tmp14_ = self->priv->_scheme;
				_tmp14__length1 = self->priv->_scheme_length1;
				if (!(_tmp13_->index < _tmp14__length1)) {
					break;
				}
			}
			_tmp12_ = FALSE;
			_tmp15_ = self->priv->_scheme;
			_tmp15__length1 = self->priv->_scheme_length1;
			_tmp16_ = state;
			_tmp17_ = _tmp15_[_tmp16_->index];
			_tmp18_ = _g_object_ref0 (_tmp17_);
			_g_object_unref0 (scheme_element);
			scheme_element = _tmp18_;
			_tmp20_ = scheme_element;
			_tmp22_ = baladoc_rule_try_to_apply ((BaladocRule*) self, _tmp20_, token, parser, &_tmp21_, &_inner_error0_);
			handled = _tmp21_;
			_tmp19_ = _tmp22_;
			if (G_UNLIKELY (_inner_error0_ != NULL)) {
				if (_inner_error0_->domain == BALADOC_PARSER_ERROR) {
					gboolean _tmp23_ = FALSE;
					g_propagate_error (error, _inner_error0_);
					_g_object_unref0 (scheme_element);
					_g_object_unref0 (state);
					return _tmp23_;
				} else {
					gboolean _tmp24_ = FALSE;
					_g_object_unref0 (scheme_element);
					_g_object_unref0 (state);
					g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
					g_clear_error (&_inner_error0_);
					return _tmp24_;
				}
			}
			if (_tmp19_) {
				BaladocSequenceRuleState* _tmp25_;
				gint _tmp26_;
				_tmp25_ = state;
				_tmp26_ = _tmp25_->index;
				_tmp25_->index = _tmp26_ + 1;
				result = handled;
				_g_object_unref0 (scheme_element);
				_g_object_unref0 (state);
				return result;
			}
			_tmp27_ = scheme_element;
			if (!baladoc_rule_is_optional_rule ((BaladocRule*) self, _tmp27_)) {
				break;
			} else {
				GObject* _tmp28_;
				_tmp28_ = scheme_element;
				baladoc_rule_do_skip (G_TYPE_CHECK_INSTANCE_CAST (_tmp28_, BALADOC_TYPE_RULE, BaladocRule), parser, &_inner_error0_);
				if (G_UNLIKELY (_inner_error0_ != NULL)) {
					if (_inner_error0_->domain == BALADOC_PARSER_ERROR) {
						gboolean _tmp29_ = FALSE;
						g_propagate_error (error, _inner_error0_);
						_g_object_unref0 (scheme_element);
						_g_object_unref0 (state);
						return _tmp29_;
					} else {
						gboolean _tmp30_ = FALSE;
						_g_object_unref0 (scheme_element);
						_g_object_unref0 (state);
						g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
						g_clear_error (&_inner_error0_);
						return _tmp30_;
					}
				}
			}
			_tmp31_ = state;
			_tmp32_ = _tmp31_->index;
			_tmp31_->index = _tmp32_ + 1;
		}
	}
	_tmp33_ = state;
	_tmp34_ = self->priv->_scheme;
	_tmp34__length1 = self->priv->_scheme_length1;
	if (_tmp33_->index == _tmp34__length1) {
		baladoc_rule_do_reduce ((BaladocRule*) self, parser, &_inner_error0_);
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			if (_inner_error0_->domain == BALADOC_PARSER_ERROR) {
				gboolean _tmp35_ = FALSE;
				g_propagate_error (error, _inner_error0_);
				_g_object_unref0 (scheme_element);
				_g_object_unref0 (state);
				return _tmp35_;
			} else {
				gboolean _tmp36_ = FALSE;
				_g_object_unref0 (scheme_element);
				_g_object_unref0 (state);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
				g_clear_error (&_inner_error0_);
				return _tmp36_;
			}
		}
		result = FALSE;
		_g_object_unref0 (scheme_element);
		_g_object_unref0 (state);
		return result;
	}
	_tmp37_ = scheme_element;
	if (BALADOC_IS_TOKEN_TYPE (_tmp37_)) {
		GObject* _tmp38_;
		const gchar* _tmp39_;
		gchar* _tmp40_;
		gchar* _tmp41_;
		_tmp38_ = scheme_element;
		_tmp39_ = baladoc_token_type_to_pretty_string (G_TYPE_CHECK_INSTANCE_CAST (_tmp38_, BALADOC_TYPE_TOKEN_TYPE, BaladocTokenType));
		_tmp40_ = g_strdup_printf ("expected %s", _tmp39_);
		_tmp41_ = _tmp40_;
		baladoc_parser_callback_error (parser, token, _tmp41_, &_inner_error0_);
		_g_free0 (_tmp41_);
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			if (_inner_error0_->domain == BALADOC_PARSER_ERROR) {
				gboolean _tmp42_ = FALSE;
				g_propagate_error (error, _inner_error0_);
				_g_object_unref0 (scheme_element);
				_g_object_unref0 (state);
				return _tmp42_;
			} else {
				gboolean _tmp43_ = FALSE;
				_g_object_unref0 (scheme_element);
				_g_object_unref0 (state);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
				g_clear_error (&_inner_error0_);
				return _tmp43_;
			}
		}
	} else {
		baladoc_parser_callback_error (parser, token, "unexpected token", &_inner_error0_);
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			if (_inner_error0_->domain == BALADOC_PARSER_ERROR) {
				gboolean _tmp44_ = FALSE;
				g_propagate_error (error, _inner_error0_);
				_g_object_unref0 (scheme_element);
				_g_object_unref0 (state);
				return _tmp44_;
			} else {
				gboolean _tmp45_ = FALSE;
				_g_object_unref0 (scheme_element);
				_g_object_unref0 (state);
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
				g_clear_error (&_inner_error0_);
				return _tmp45_;
			}
		}
	}
	g_assert_not_reached ();
	_g_object_unref0 (scheme_element);
	_g_object_unref0 (state);
}

static gboolean
baladoc_sequence_rule_real_would_accept_token (BaladocRule* base,
                                               BaladocToken* token,
                                               GObject* rule_state)
{
	BaladocSequenceRule * self;
	BaladocSequenceRuleState* state = NULL;
	BaladocSequenceRuleState* _tmp0_;
	gboolean result = FALSE;
	self = (BaladocSequenceRule*) base;
	g_return_val_if_fail (token != NULL, FALSE);
	_tmp0_ = _g_object_ref0 (BALADOC_SEQUENCE_RULE_IS_STATE (rule_state) ? ((BaladocSequenceRuleState*) rule_state) : NULL);
	state = _tmp0_;
	result = baladoc_sequence_rule_test_token (self, state->index, token);
	_g_object_unref0 (state);
	return result;
}

static gboolean
baladoc_sequence_rule_real_would_reduce (BaladocRule* base,
                                         BaladocToken* token,
                                         GObject* rule_state)
{
	BaladocSequenceRule * self;
	BaladocSequenceRuleState* state = NULL;
	BaladocSequenceRuleState* _tmp0_;
	gboolean _tmp1_ = FALSE;
	BaladocSequenceRuleState* _tmp2_;
	GObject** _tmp3_;
	gint _tmp3__length1;
	gboolean result = FALSE;
	self = (BaladocSequenceRule*) base;
	g_return_val_if_fail (token != NULL, FALSE);
	_tmp0_ = _g_object_ref0 (BALADOC_SEQUENCE_RULE_IS_STATE (rule_state) ? ((BaladocSequenceRuleState*) rule_state) : NULL);
	state = _tmp0_;
	_tmp2_ = state;
	_tmp3_ = self->priv->_scheme;
	_tmp3__length1 = self->priv->_scheme_length1;
	if (_tmp2_->index == _tmp3__length1) {
		_tmp1_ = TRUE;
	} else {
		BaladocSequenceRuleState* _tmp4_;
		_tmp4_ = state;
		_tmp1_ = baladoc_sequence_rule_test_reduce (self, _tmp4_->index, token);
	}
	result = _tmp1_;
	_g_object_unref0 (state);
	return result;
}

static gchar*
baladoc_sequence_rule_real_to_string (BaladocRule* base,
                                      GObject* rule_state)
{
	BaladocSequenceRule * self;
	BaladocSequenceRuleState* state = NULL;
	BaladocSequenceRuleState* _tmp0_;
	BaladocSequenceRuleState* _tmp1_;
	const gchar* _tmp3_ = NULL;
	const gchar* _tmp4_;
	const gchar* _tmp5_;
	BaladocSequenceRuleState* _tmp8_;
	GObject** _tmp9_;
	gint _tmp9__length1;
	gchar* _tmp10_;
	gchar* result = NULL;
	self = (BaladocSequenceRule*) base;
	_tmp0_ = _g_object_ref0 (BALADOC_SEQUENCE_RULE_IS_STATE (rule_state) ? ((BaladocSequenceRuleState*) rule_state) : NULL);
	state = _tmp0_;
	_tmp1_ = state;
	if (_tmp1_ == NULL) {
		BaladocSequenceRuleState* _tmp2_;
		_tmp2_ = baladoc_sequence_rule_state_new ();
		_g_object_unref0 (state);
		state = _tmp2_;
	}
	_tmp4_ = baladoc_rule_get_name ((BaladocRule*) self);
	_tmp5_ = _tmp4_;
	if (_tmp5_ != NULL) {
		const gchar* _tmp6_;
		const gchar* _tmp7_;
		_tmp6_ = baladoc_rule_get_name ((BaladocRule*) self);
		_tmp7_ = _tmp6_;
		_tmp3_ = _tmp7_;
	} else {
		_tmp3_ = " ";
	}
	_tmp8_ = state;
	_tmp9_ = self->priv->_scheme;
	_tmp9__length1 = self->priv->_scheme_length1;
	_tmp10_ = g_strdup_printf ("%-15s%-15s(index=%d/%d)", _tmp3_, "[seq]", _tmp8_->index, _tmp9__length1);
	result = _tmp10_;
	_g_object_unref0 (state);
	return result;
}

static BaladocSequenceRuleState*
baladoc_sequence_rule_state_construct (GType object_type)
{
	BaladocSequenceRuleState * self = NULL;
	self = (BaladocSequenceRuleState*) g_object_new (object_type, NULL);
	return self;
}

static BaladocSequenceRuleState*
baladoc_sequence_rule_state_new (void)
{
	return baladoc_sequence_rule_state_construct (BALADOC_SEQUENCE_RULE_TYPE_STATE);
}

static void
baladoc_sequence_rule_state_class_init (BaladocSequenceRuleStateClass * klass,
                                        gpointer klass_data)
{
	baladoc_sequence_rule_state_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = baladoc_sequence_rule_state_finalize;
}

static void
baladoc_sequence_rule_state_instance_init (BaladocSequenceRuleState * self,
                                           gpointer klass)
{
	self->index = 0;
}

static void
baladoc_sequence_rule_state_finalize (GObject * obj)
{
	BaladocSequenceRuleState * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_SEQUENCE_RULE_TYPE_STATE, BaladocSequenceRuleState);
	G_OBJECT_CLASS (baladoc_sequence_rule_state_parent_class)->finalize (obj);
}

static GType
baladoc_sequence_rule_state_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BaladocSequenceRuleStateClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_sequence_rule_state_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BaladocSequenceRuleState), 0, (GInstanceInitFunc) baladoc_sequence_rule_state_instance_init, NULL };
	GType baladoc_sequence_rule_state_type_id;
	baladoc_sequence_rule_state_type_id = g_type_register_static (G_TYPE_OBJECT, "BaladocSequenceRuleState", &g_define_type_info, 0);
	return baladoc_sequence_rule_state_type_id;
}

static GType
baladoc_sequence_rule_state_get_type (void)
{
	static volatile gsize baladoc_sequence_rule_state_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_sequence_rule_state_type_id__volatile)) {
		GType baladoc_sequence_rule_state_type_id;
		baladoc_sequence_rule_state_type_id = baladoc_sequence_rule_state_get_type_once ();
		g_once_init_leave (&baladoc_sequence_rule_state_type_id__volatile, baladoc_sequence_rule_state_type_id);
	}
	return baladoc_sequence_rule_state_type_id__volatile;
}

static void
baladoc_sequence_rule_class_init (BaladocSequenceRuleClass * klass,
                                  gpointer klass_data)
{
	baladoc_sequence_rule_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &BaladocSequenceRule_private_offset);
	((BaladocRuleClass *) klass)->is_optional = (gboolean (*) (BaladocRule*)) baladoc_sequence_rule_real_is_optional;
	((BaladocRuleClass *) klass)->starts_with_token = (gboolean (*) (BaladocRule*, BaladocToken*)) baladoc_sequence_rule_real_starts_with_token;
	((BaladocRuleClass *) klass)->accept_token = (gboolean (*) (BaladocRule*, BaladocToken*, BaladocParserCallback*, BaladocRuleForward, GError**)) baladoc_sequence_rule_real_accept_token;
	((BaladocRuleClass *) klass)->would_accept_token = (gboolean (*) (BaladocRule*, BaladocToken*, GObject*)) baladoc_sequence_rule_real_would_accept_token;
	((BaladocRuleClass *) klass)->would_reduce = (gboolean (*) (BaladocRule*, BaladocToken*, GObject*)) baladoc_sequence_rule_real_would_reduce;
	((BaladocRuleClass *) klass)->to_string = (gchar* (*) (BaladocRule*, GObject*)) baladoc_sequence_rule_real_to_string;
	G_OBJECT_CLASS (klass)->finalize = baladoc_sequence_rule_finalize;
}

static void
baladoc_sequence_rule_instance_init (BaladocSequenceRule * self,
                                     gpointer klass)
{
	self->priv = baladoc_sequence_rule_get_instance_private (self);
}

static void
baladoc_sequence_rule_finalize (GObject * obj)
{
	BaladocSequenceRule * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALADOC_TYPE_SEQUENCE_RULE, BaladocSequenceRule);
	self->priv->_scheme = (_bala_array_free (self->priv->_scheme, self->priv->_scheme_length1, (GDestroyNotify) g_object_unref), NULL);
	G_OBJECT_CLASS (baladoc_sequence_rule_parent_class)->finalize (obj);
}

static GType
baladoc_sequence_rule_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BaladocSequenceRuleClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_sequence_rule_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BaladocSequenceRule), 0, (GInstanceInitFunc) baladoc_sequence_rule_instance_init, NULL };
	GType baladoc_sequence_rule_type_id;
	baladoc_sequence_rule_type_id = g_type_register_static (BALADOC_TYPE_RULE, "BaladocSequenceRule", &g_define_type_info, 0);
	BaladocSequenceRule_private_offset = g_type_add_instance_private (baladoc_sequence_rule_type_id, sizeof (BaladocSequenceRulePrivate));
	return baladoc_sequence_rule_type_id;
}

G_GNUC_INTERNAL GType
baladoc_sequence_rule_get_type (void)
{
	static volatile gsize baladoc_sequence_rule_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_sequence_rule_type_id__volatile)) {
		GType baladoc_sequence_rule_type_id;
		baladoc_sequence_rule_type_id = baladoc_sequence_rule_get_type_once ();
		g_once_init_leave (&baladoc_sequence_rule_type_id__volatile, baladoc_sequence_rule_type_id);
	}
	return baladoc_sequence_rule_type_id__volatile;
}

static void
_bala_array_destroy (gpointer array,
                     gint array_length,
                     GDestroyNotify destroy_func)
{
	if ((array != NULL) && (destroy_func != NULL)) {
		gint i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}

static void
_bala_array_free (gpointer array,
                  gint array_length,
                  GDestroyNotify destroy_func)
{
	_bala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}

