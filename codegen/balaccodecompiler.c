/* balaccodecompiler.c generated by balac, the Bala compiler
 * generated from balaccodecompiler.bala, do not modify */

/* balaccodecompiler.bala
 *
 * Copyright (C) 2007-2009  Jürg Billeter
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

#include "balacodegen.h"
#include <bala.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <balagee.h>
#include <glib-object.h>
#include <stdio.h>
#include <glib/gstdio.h>
#include <gobject/gvaluecollector.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _bala_iterable_unref0(var) ((var == NULL) ? NULL : (var = (bala_iterable_unref (var), NULL)))
#define _bala_source_file_unref0(var) ((var == NULL) ? NULL : (var = (bala_source_file_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _BalaParamSpecCCodeCompiler BalaParamSpecCCodeCompiler;

struct _BalaParamSpecCCodeCompiler {
	GParamSpec parent_instance;
};

static gpointer bala_ccode_compiler_parent_class = NULL;

static void bala_ccode_compiler_finalize (BalaCCodeCompiler * obj);
static GType bala_ccode_compiler_get_type_once (void);

BalaCCodeCompiler*
bala_ccode_compiler_construct (GType object_type)
{
	BalaCCodeCompiler* self = NULL;
	self = (BalaCCodeCompiler*) g_type_create_instance (object_type);
	return self;
}

BalaCCodeCompiler*
bala_ccode_compiler_new (void)
{
	return bala_ccode_compiler_construct (BALA_TYPE_CCODE_COMPILER);
}

/**
 * Compile generated C code to object code and optionally link object
 * files.
 *
 * @param context a code context
 */
static gpointer
_bala_iterable_ref0 (gpointer self)
{
	return self ? bala_iterable_ref (self) : NULL;
}

static gchar*
string_strip (const gchar* self)
{
	gchar* _result_ = NULL;
	gchar* _tmp0_;
	gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = g_strdup (self);
	_result_ = _tmp0_;
	g_strstrip (_result_);
	result = _result_;
	return result;
}

void
bala_ccode_compiler_compile (BalaCCodeCompiler* self,
                             BalaCodeContext* context,
                             const gchar* cc_command,
                             gchar** cc_options,
                             gint cc_options_length1)
{
	gchar* pc = NULL;
	gchar* _tmp0_;
	BalaProfile _tmp1_;
	BalaProfile _tmp2_;
	gchar* pkgflags = NULL;
	const gchar* _tmp20_;
	gint _tmp21_;
	gint _tmp22_;
	gchar* cmdline = NULL;
	gchar* _tmp27_;
	gboolean _tmp28_;
	gboolean _tmp29_;
	gboolean _tmp32_;
	gboolean _tmp33_;
	BalaList* source_files = NULL;
	BalaList* _tmp61_;
	BalaList* _tmp62_;
	BalaList* c_source_files = NULL;
	BalaList* _tmp84_;
	BalaList* _tmp85_;
	const gchar* _tmp102_;
	const gchar* _tmp103_;
	gchar* _tmp104_;
	gchar* _tmp105_;
	gchar* _tmp106_;
	gchar* _tmp107_;
	gchar* _tmp108_;
	gboolean _tmp117_;
	gboolean _tmp118_;
	gboolean _tmp127_;
	gboolean _tmp128_;
	GError* _inner_error0_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (context != NULL);
	_tmp0_ = g_strdup ("");
	pc = _tmp0_;
	_tmp1_ = bala_code_context_get_profile (context);
	_tmp2_ = _tmp1_;
	if (_tmp2_ == BALA_PROFILE_GOBJECT) {
		const gchar* _tmp3_;
		gchar* _tmp4_;
		_tmp3_ = pc;
		_tmp4_ = g_strconcat (_tmp3_, " gobject-2.0", NULL);
		_g_free0 (pc);
		pc = _tmp4_;
	}
	{
		BalaList* _pkg_list = NULL;
		BalaList* _tmp5_;
		BalaList* _tmp6_;
		gint _pkg_size = 0;
		BalaList* _tmp7_;
		gint _tmp8_;
		gint _tmp9_;
		gint _pkg_index = 0;
		_tmp5_ = bala_code_context_get_packages (context);
		_tmp6_ = _bala_iterable_ref0 (_tmp5_);
		_pkg_list = _tmp6_;
		_tmp7_ = _pkg_list;
		_tmp8_ = bala_collection_get_size ((BalaCollection*) _tmp7_);
		_tmp9_ = _tmp8_;
		_pkg_size = _tmp9_;
		_pkg_index = -1;
		while (TRUE) {
			gint _tmp10_;
			gint _tmp11_;
			gchar* pkg = NULL;
			BalaList* _tmp12_;
			gpointer _tmp13_;
			const gchar* _tmp14_;
			_pkg_index = _pkg_index + 1;
			_tmp10_ = _pkg_index;
			_tmp11_ = _pkg_size;
			if (!(_tmp10_ < _tmp11_)) {
				break;
			}
			_tmp12_ = _pkg_list;
			_tmp13_ = bala_list_get (_tmp12_, _pkg_index);
			pkg = (gchar*) _tmp13_;
			_tmp14_ = pkg;
			if (bala_code_context_pkg_config_exists (context, _tmp14_)) {
				const gchar* _tmp15_;
				const gchar* _tmp16_;
				gchar* _tmp17_;
				gchar* _tmp18_;
				gchar* _tmp19_;
				_tmp15_ = pc;
				_tmp16_ = pkg;
				_tmp17_ = g_strconcat (" ", _tmp16_, NULL);
				_tmp18_ = _tmp17_;
				_tmp19_ = g_strconcat (_tmp15_, _tmp18_, NULL);
				_g_free0 (pc);
				pc = _tmp19_;
				_g_free0 (_tmp18_);
			}
			_g_free0 (pkg);
		}
		_bala_iterable_unref0 (_pkg_list);
	}
	_tmp20_ = pc;
	_tmp21_ = strlen (_tmp20_);
	_tmp22_ = _tmp21_;
	if (_tmp22_ > 0) {
		const gchar* _tmp23_;
		gchar* _tmp24_;
		const gchar* _tmp25_;
		_tmp23_ = pc;
		_tmp24_ = bala_code_context_pkg_config_compile_flags (context, _tmp23_);
		_g_free0 (pkgflags);
		pkgflags = _tmp24_;
		_tmp25_ = pkgflags;
		if (_tmp25_ == NULL) {
			_g_free0 (pkgflags);
			_g_free0 (pc);
			return;
		}
	} else {
		gchar* _tmp26_;
		_tmp26_ = g_strdup ("");
		_g_free0 (pkgflags);
		pkgflags = _tmp26_;
	}
	if (cc_command == NULL) {
		cc_command = "cc";
	}
	_tmp27_ = g_strdup (cc_command);
	cmdline = _tmp27_;
	_tmp28_ = bala_code_context_get_debug (context);
	_tmp29_ = _tmp28_;
	if (_tmp29_) {
		const gchar* _tmp30_;
		gchar* _tmp31_;
		_tmp30_ = cmdline;
		_tmp31_ = g_strconcat (_tmp30_, " -g", NULL);
		_g_free0 (cmdline);
		cmdline = _tmp31_;
	}
	_tmp32_ = bala_code_context_get_compile_only (context);
	_tmp33_ = _tmp32_;
	if (_tmp33_) {
		const gchar* _tmp34_;
		gchar* _tmp35_;
		_tmp34_ = cmdline;
		_tmp35_ = g_strconcat (_tmp34_, " -c", NULL);
		_g_free0 (cmdline);
		cmdline = _tmp35_;
	} else {
		const gchar* _tmp36_;
		const gchar* _tmp37_;
		_tmp36_ = bala_code_context_get_output (context);
		_tmp37_ = _tmp36_;
		if (_tmp37_ != NULL) {
			gchar* output = NULL;
			const gchar* _tmp38_;
			const gchar* _tmp39_;
			gchar* _tmp40_;
			gboolean _tmp41_ = FALSE;
			gboolean _tmp42_ = FALSE;
			const gchar* _tmp43_;
			const gchar* _tmp44_;
			const gchar* _tmp54_;
			const gchar* _tmp55_;
			gchar* _tmp56_;
			gchar* _tmp57_;
			gchar* _tmp58_;
			gchar* _tmp59_;
			gchar* _tmp60_;
			_tmp38_ = bala_code_context_get_output (context);
			_tmp39_ = _tmp38_;
			_tmp40_ = g_strdup (_tmp39_);
			output = _tmp40_;
			_tmp43_ = bala_code_context_get_directory (context);
			_tmp44_ = _tmp43_;
			if (_tmp44_ != NULL) {
				const gchar* _tmp45_;
				const gchar* _tmp46_;
				_tmp45_ = bala_code_context_get_directory (context);
				_tmp46_ = _tmp45_;
				_tmp42_ = g_strcmp0 (_tmp46_, "") != 0;
			} else {
				_tmp42_ = FALSE;
			}
			if (_tmp42_) {
				const gchar* _tmp47_;
				const gchar* _tmp48_;
				_tmp47_ = bala_code_context_get_output (context);
				_tmp48_ = _tmp47_;
				_tmp41_ = !g_path_is_absolute (_tmp48_);
			} else {
				_tmp41_ = FALSE;
			}
			if (_tmp41_) {
				const gchar* _tmp49_;
				const gchar* _tmp50_;
				const gchar* _tmp51_;
				const gchar* _tmp52_;
				gchar* _tmp53_;
				_tmp49_ = bala_code_context_get_directory (context);
				_tmp50_ = _tmp49_;
				_tmp51_ = bala_code_context_get_output (context);
				_tmp52_ = _tmp51_;
				_tmp53_ = g_strdup_printf ("%s%c%s", _tmp50_, (gint) G_DIR_SEPARATOR, _tmp52_);
				_g_free0 (output);
				output = _tmp53_;
			}
			_tmp54_ = cmdline;
			_tmp55_ = output;
			_tmp56_ = g_shell_quote (_tmp55_);
			_tmp57_ = _tmp56_;
			_tmp58_ = g_strconcat (" -o ", _tmp57_, NULL);
			_tmp59_ = _tmp58_;
			_tmp60_ = g_strconcat (_tmp54_, _tmp59_, NULL);
			_g_free0 (cmdline);
			cmdline = _tmp60_;
			_g_free0 (_tmp59_);
			_g_free0 (_tmp57_);
			_g_free0 (output);
		}
	}
	_tmp61_ = bala_code_context_get_source_files (context);
	_tmp62_ = _bala_iterable_ref0 (_tmp61_);
	source_files = _tmp62_;
	{
		BalaList* _file_list = NULL;
		BalaList* _tmp63_;
		BalaList* _tmp64_;
		gint _file_size = 0;
		BalaList* _tmp65_;
		gint _tmp66_;
		gint _tmp67_;
		gint _file_index = 0;
		_tmp63_ = source_files;
		_tmp64_ = _bala_iterable_ref0 (_tmp63_);
		_file_list = _tmp64_;
		_tmp65_ = _file_list;
		_tmp66_ = bala_collection_get_size ((BalaCollection*) _tmp65_);
		_tmp67_ = _tmp66_;
		_file_size = _tmp67_;
		_file_index = -1;
		while (TRUE) {
			gint _tmp68_;
			gint _tmp69_;
			BalaSourceFile* file = NULL;
			BalaList* _tmp70_;
			gpointer _tmp71_;
			BalaSourceFile* _tmp72_;
			BalaSourceFileType _tmp73_;
			BalaSourceFileType _tmp74_;
			_file_index = _file_index + 1;
			_tmp68_ = _file_index;
			_tmp69_ = _file_size;
			if (!(_tmp68_ < _tmp69_)) {
				break;
			}
			_tmp70_ = _file_list;
			_tmp71_ = bala_list_get (_tmp70_, _file_index);
			file = (BalaSourceFile*) _tmp71_;
			_tmp72_ = file;
			_tmp73_ = bala_source_file_get_file_type (_tmp72_);
			_tmp74_ = _tmp73_;
			if (_tmp74_ == BALA_SOURCE_FILE_TYPE_SOURCE) {
				const gchar* _tmp75_;
				BalaSourceFile* _tmp76_;
				gchar* _tmp77_;
				gchar* _tmp78_;
				gchar* _tmp79_;
				gchar* _tmp80_;
				gchar* _tmp81_;
				gchar* _tmp82_;
				gchar* _tmp83_;
				_tmp75_ = cmdline;
				_tmp76_ = file;
				_tmp77_ = bala_source_file_get_csource_filename (_tmp76_);
				_tmp78_ = _tmp77_;
				_tmp79_ = g_shell_quote (_tmp78_);
				_tmp80_ = _tmp79_;
				_tmp81_ = g_strconcat (" ", _tmp80_, NULL);
				_tmp82_ = _tmp81_;
				_tmp83_ = g_strconcat (_tmp75_, _tmp82_, NULL);
				_g_free0 (cmdline);
				cmdline = _tmp83_;
				_g_free0 (_tmp82_);
				_g_free0 (_tmp80_);
				_g_free0 (_tmp78_);
			}
			_bala_source_file_unref0 (file);
		}
		_bala_iterable_unref0 (_file_list);
	}
	_tmp84_ = bala_code_context_get_c_source_files (context);
	_tmp85_ = _bala_iterable_ref0 (_tmp84_);
	c_source_files = _tmp85_;
	{
		BalaList* _file_list = NULL;
		BalaList* _tmp86_;
		BalaList* _tmp87_;
		gint _file_size = 0;
		BalaList* _tmp88_;
		gint _tmp89_;
		gint _tmp90_;
		gint _file_index = 0;
		_tmp86_ = c_source_files;
		_tmp87_ = _bala_iterable_ref0 (_tmp86_);
		_file_list = _tmp87_;
		_tmp88_ = _file_list;
		_tmp89_ = bala_collection_get_size ((BalaCollection*) _tmp88_);
		_tmp90_ = _tmp89_;
		_file_size = _tmp90_;
		_file_index = -1;
		while (TRUE) {
			gint _tmp91_;
			gint _tmp92_;
			gchar* file = NULL;
			BalaList* _tmp93_;
			gpointer _tmp94_;
			const gchar* _tmp95_;
			const gchar* _tmp96_;
			gchar* _tmp97_;
			gchar* _tmp98_;
			gchar* _tmp99_;
			gchar* _tmp100_;
			gchar* _tmp101_;
			_file_index = _file_index + 1;
			_tmp91_ = _file_index;
			_tmp92_ = _file_size;
			if (!(_tmp91_ < _tmp92_)) {
				break;
			}
			_tmp93_ = _file_list;
			_tmp94_ = bala_list_get (_tmp93_, _file_index);
			file = (gchar*) _tmp94_;
			_tmp95_ = cmdline;
			_tmp96_ = file;
			_tmp97_ = g_shell_quote (_tmp96_);
			_tmp98_ = _tmp97_;
			_tmp99_ = g_strconcat (" ", _tmp98_, NULL);
			_tmp100_ = _tmp99_;
			_tmp101_ = g_strconcat (_tmp95_, _tmp100_, NULL);
			_g_free0 (cmdline);
			cmdline = _tmp101_;
			_g_free0 (_tmp100_);
			_g_free0 (_tmp98_);
			_g_free0 (file);
		}
		_bala_iterable_unref0 (_file_list);
	}
	_tmp102_ = cmdline;
	_tmp103_ = pkgflags;
	_tmp104_ = string_strip (_tmp103_);
	_tmp105_ = _tmp104_;
	_tmp106_ = g_strconcat (" ", _tmp105_, NULL);
	_tmp107_ = _tmp106_;
	_tmp108_ = g_strconcat (_tmp102_, _tmp107_, NULL);
	_g_free0 (cmdline);
	cmdline = _tmp108_;
	_g_free0 (_tmp107_);
	_g_free0 (_tmp105_);
	{
		gchar** cc_option_collection = NULL;
		gint cc_option_collection_length1 = 0;
		gint _cc_option_collection_size_ = 0;
		gint cc_option_it = 0;
		cc_option_collection = cc_options;
		cc_option_collection_length1 = cc_options_length1;
		for (cc_option_it = 0; cc_option_it < cc_option_collection_length1; cc_option_it = cc_option_it + 1) {
			gchar* _tmp109_;
			gchar* cc_option = NULL;
			_tmp109_ = g_strdup (cc_option_collection[cc_option_it]);
			cc_option = _tmp109_;
			{
				const gchar* _tmp110_;
				const gchar* _tmp111_;
				gchar* _tmp112_;
				gchar* _tmp113_;
				gchar* _tmp114_;
				gchar* _tmp115_;
				gchar* _tmp116_;
				_tmp110_ = cmdline;
				_tmp111_ = cc_option;
				_tmp112_ = g_shell_quote (_tmp111_);
				_tmp113_ = _tmp112_;
				_tmp114_ = g_strconcat (" ", _tmp113_, NULL);
				_tmp115_ = _tmp114_;
				_tmp116_ = g_strconcat (_tmp110_, _tmp115_, NULL);
				_g_free0 (cmdline);
				cmdline = _tmp116_;
				_g_free0 (_tmp115_);
				_g_free0 (_tmp113_);
				_g_free0 (cc_option);
			}
		}
	}
	_tmp117_ = bala_code_context_get_verbose_mode (context);
	_tmp118_ = _tmp117_;
	if (_tmp118_) {
		FILE* _tmp119_;
		const gchar* _tmp120_;
		_tmp119_ = stdout;
		_tmp120_ = cmdline;
		fprintf (_tmp119_, "%s\n", _tmp120_);
	}
	{
		gint exit_status = 0;
		const gchar* _tmp121_;
		gint _tmp122_ = 0;
		_tmp121_ = cmdline;
		g_spawn_command_line_sync (_tmp121_, NULL, NULL, &_tmp122_, &_inner_error0_);
		exit_status = _tmp122_;
		if (G_UNLIKELY (_inner_error0_ != NULL)) {
			if (_inner_error0_->domain == G_SPAWN_ERROR) {
				goto __catch0_g_spawn_error;
			}
			_bala_iterable_unref0 (c_source_files);
			_bala_iterable_unref0 (source_files);
			_g_free0 (cmdline);
			_g_free0 (pkgflags);
			_g_free0 (pc);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
			g_clear_error (&_inner_error0_);
			return;
		}
		if (exit_status != 0) {
			gchar* _tmp123_;
			gchar* _tmp124_;
			_tmp123_ = g_strdup_printf ("cc exited with status %d", exit_status);
			_tmp124_ = _tmp123_;
			bala_report_error (NULL, _tmp124_);
			_g_free0 (_tmp124_);
		}
	}
	goto __finally0;
	__catch0_g_spawn_error:
	{
		GError* e = NULL;
		GError* _tmp125_;
		const gchar* _tmp126_;
		e = _inner_error0_;
		_inner_error0_ = NULL;
		_tmp125_ = e;
		_tmp126_ = _tmp125_->message;
		bala_report_error (NULL, _tmp126_);
		_g_error_free0 (e);
	}
	__finally0:
	if (G_UNLIKELY (_inner_error0_ != NULL)) {
		_bala_iterable_unref0 (c_source_files);
		_bala_iterable_unref0 (source_files);
		_g_free0 (cmdline);
		_g_free0 (pkgflags);
		_g_free0 (pc);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error0_->message, g_quark_to_string (_inner_error0_->domain), _inner_error0_->code);
		g_clear_error (&_inner_error0_);
		return;
	}
	_tmp127_ = bala_code_context_get_save_csources (context);
	_tmp128_ = _tmp127_;
	if (!_tmp128_) {
		{
			BalaList* _file_list = NULL;
			BalaList* _tmp129_;
			BalaList* _tmp130_;
			gint _file_size = 0;
			BalaList* _tmp131_;
			gint _tmp132_;
			gint _tmp133_;
			gint _file_index = 0;
			_tmp129_ = source_files;
			_tmp130_ = _bala_iterable_ref0 (_tmp129_);
			_file_list = _tmp130_;
			_tmp131_ = _file_list;
			_tmp132_ = bala_collection_get_size ((BalaCollection*) _tmp131_);
			_tmp133_ = _tmp132_;
			_file_size = _tmp133_;
			_file_index = -1;
			while (TRUE) {
				gint _tmp134_;
				gint _tmp135_;
				BalaSourceFile* file = NULL;
				BalaList* _tmp136_;
				gpointer _tmp137_;
				BalaSourceFile* _tmp138_;
				BalaSourceFileType _tmp139_;
				BalaSourceFileType _tmp140_;
				_file_index = _file_index + 1;
				_tmp134_ = _file_index;
				_tmp135_ = _file_size;
				if (!(_tmp134_ < _tmp135_)) {
					break;
				}
				_tmp136_ = _file_list;
				_tmp137_ = bala_list_get (_tmp136_, _file_index);
				file = (BalaSourceFile*) _tmp137_;
				_tmp138_ = file;
				_tmp139_ = bala_source_file_get_file_type (_tmp138_);
				_tmp140_ = _tmp139_;
				if (_tmp140_ == BALA_SOURCE_FILE_TYPE_SOURCE) {
					BalaSourceFile* _tmp141_;
					gchar* _tmp142_;
					gchar* _tmp143_;
					_tmp141_ = file;
					_tmp142_ = bala_source_file_get_csource_filename (_tmp141_);
					_tmp143_ = _tmp142_;
					g_unlink (_tmp143_);
					_g_free0 (_tmp143_);
				}
				_bala_source_file_unref0 (file);
			}
			_bala_iterable_unref0 (_file_list);
		}
	}
	_bala_iterable_unref0 (c_source_files);
	_bala_iterable_unref0 (source_files);
	_g_free0 (cmdline);
	_g_free0 (pkgflags);
	_g_free0 (pc);
}

static void
bala_value_ccode_compiler_init (GValue* value)
{
	value->data[0].v_pointer = NULL;
}

static void
bala_value_ccode_compiler_free_value (GValue* value)
{
	if (value->data[0].v_pointer) {
		bala_ccode_compiler_unref (value->data[0].v_pointer);
	}
}

static void
bala_value_ccode_compiler_copy_value (const GValue* src_value,
                                      GValue* dest_value)
{
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = bala_ccode_compiler_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}

static gpointer
bala_value_ccode_compiler_peek_pointer (const GValue* value)
{
	return value->data[0].v_pointer;
}

static gchar*
bala_value_ccode_compiler_collect_value (GValue* value,
                                         guint n_collect_values,
                                         GTypeCValue* collect_values,
                                         guint collect_flags)
{
	if (collect_values[0].v_pointer) {
		BalaCCodeCompiler * object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = bala_ccode_compiler_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}

static gchar*
bala_value_ccode_compiler_lcopy_value (const GValue* value,
                                       guint n_collect_values,
                                       GTypeCValue* collect_values,
                                       guint collect_flags)
{
	BalaCCodeCompiler ** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = bala_ccode_compiler_ref (value->data[0].v_pointer);
	}
	return NULL;
}

GParamSpec*
bala_param_spec_ccode_compiler (const gchar* name,
                                const gchar* nick,
                                const gchar* blurb,
                                GType object_type,
                                GParamFlags flags)
{
	BalaParamSpecCCodeCompiler* spec;
	g_return_val_if_fail (g_type_is_a (object_type, BALA_TYPE_CCODE_COMPILER), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}

gpointer
bala_value_get_ccode_compiler (const GValue* value)
{
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALA_TYPE_CCODE_COMPILER), NULL);
	return value->data[0].v_pointer;
}

void
bala_value_set_ccode_compiler (GValue* value,
                               gpointer v_object)
{
	BalaCCodeCompiler * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALA_TYPE_CCODE_COMPILER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, BALA_TYPE_CCODE_COMPILER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		bala_ccode_compiler_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		bala_ccode_compiler_unref (old);
	}
}

void
bala_value_take_ccode_compiler (GValue* value,
                                gpointer v_object)
{
	BalaCCodeCompiler * old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, BALA_TYPE_CCODE_COMPILER));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, BALA_TYPE_CCODE_COMPILER));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		bala_ccode_compiler_unref (old);
	}
}

static void
bala_ccode_compiler_class_init (BalaCCodeCompilerClass * klass,
                                gpointer klass_data)
{
	bala_ccode_compiler_parent_class = g_type_class_peek_parent (klass);
	((BalaCCodeCompilerClass *) klass)->finalize = bala_ccode_compiler_finalize;
}

static void
bala_ccode_compiler_instance_init (BalaCCodeCompiler * self,
                                   gpointer klass)
{
	self->ref_count = 1;
}

static void
bala_ccode_compiler_finalize (BalaCCodeCompiler * obj)
{
	BalaCCodeCompiler * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, BALA_TYPE_CCODE_COMPILER, BalaCCodeCompiler);
	g_signal_handlers_destroy (self);
}

/**
 * Interface to the C compiler.
 */
static GType
bala_ccode_compiler_get_type_once (void)
{
	static const GTypeValueTable g_define_type_value_table = { bala_value_ccode_compiler_init, bala_value_ccode_compiler_free_value, bala_value_ccode_compiler_copy_value, bala_value_ccode_compiler_peek_pointer, "p", bala_value_ccode_compiler_collect_value, "p", bala_value_ccode_compiler_lcopy_value };
	static const GTypeInfo g_define_type_info = { sizeof (BalaCCodeCompilerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) bala_ccode_compiler_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BalaCCodeCompiler), 0, (GInstanceInitFunc) bala_ccode_compiler_instance_init, &g_define_type_value_table };
	static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
	GType bala_ccode_compiler_type_id;
	bala_ccode_compiler_type_id = g_type_register_fundamental (g_type_fundamental_next (), "BalaCCodeCompiler", &g_define_type_info, &g_define_type_fundamental_info, 0);
	return bala_ccode_compiler_type_id;
}

GType
bala_ccode_compiler_get_type (void)
{
	static volatile gsize bala_ccode_compiler_type_id__volatile = 0;
	if (g_once_init_enter (&bala_ccode_compiler_type_id__volatile)) {
		GType bala_ccode_compiler_type_id;
		bala_ccode_compiler_type_id = bala_ccode_compiler_get_type_once ();
		g_once_init_leave (&bala_ccode_compiler_type_id__volatile, bala_ccode_compiler_type_id);
	}
	return bala_ccode_compiler_type_id__volatile;
}

gpointer
bala_ccode_compiler_ref (gpointer instance)
{
	BalaCCodeCompiler * self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}

void
bala_ccode_compiler_unref (gpointer instance)
{
	BalaCCodeCompiler * self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		BALA_CCODE_COMPILER_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}

