/* balaccodemodifiers.c generated by balac, the Bala compiler
 * generated from balaccodemodifiers.bala, do not modify */

/* balaccodemodifiers.bala
 *
 * Copyright (C) 2006-2010  Jürg Billeter
 * Copyright (C) 2006-2008  Raffaele Sandrini
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
 *	Raffaele Sandrini <raffaele@sandrini.ch>
 */

#include "balaccode.h"

static GType
bala_ccode_modifiers_get_type_once (void)
{
	static const GFlagsValue values[] = {{BALA_CCODE_MODIFIERS_NONE, "BALA_CCODE_MODIFIERS_NONE", "none"}, {BALA_CCODE_MODIFIERS_STATIC, "BALA_CCODE_MODIFIERS_STATIC", "static"}, {BALA_CCODE_MODIFIERS_REGISTER, "BALA_CCODE_MODIFIERS_REGISTER", "register"}, {BALA_CCODE_MODIFIERS_EXTERN, "BALA_CCODE_MODIFIERS_EXTERN", "extern"}, {BALA_CCODE_MODIFIERS_INLINE, "BALA_CCODE_MODIFIERS_INLINE", "inline"}, {BALA_CCODE_MODIFIERS_VOLATILE, "BALA_CCODE_MODIFIERS_VOLATILE", "volatile"}, {BALA_CCODE_MODIFIERS_DEPRECATED, "BALA_CCODE_MODIFIERS_DEPRECATED", "deprecated"}, {BALA_CCODE_MODIFIERS_THREAD_LOCAL, "BALA_CCODE_MODIFIERS_THREAD_LOCAL", "thread-local"}, {BALA_CCODE_MODIFIERS_INTERNAL, "BALA_CCODE_MODIFIERS_INTERNAL", "internal"}, {BALA_CCODE_MODIFIERS_CONST, "BALA_CCODE_MODIFIERS_CONST", "const"}, {BALA_CCODE_MODIFIERS_UNUSED, "BALA_CCODE_MODIFIERS_UNUSED", "unused"}, {BALA_CCODE_MODIFIERS_CONSTRUCTOR, "BALA_CCODE_MODIFIERS_CONSTRUCTOR", "constructor"}, {BALA_CCODE_MODIFIERS_DESTRUCTOR, "BALA_CCODE_MODIFIERS_DESTRUCTOR", "destructor"}, {BALA_CCODE_MODIFIERS_FORMAT_ARG, "BALA_CCODE_MODIFIERS_FORMAT_ARG", "format-arg"}, {BALA_CCODE_MODIFIERS_PRINTF, "BALA_CCODE_MODIFIERS_PRINTF", "printf"}, {BALA_CCODE_MODIFIERS_SCANF, "BALA_CCODE_MODIFIERS_SCANF", "scanf"}, {BALA_CCODE_MODIFIERS_NO_INLINE, "BALA_CCODE_MODIFIERS_NO_INLINE", "no-inline"}, {0, NULL, NULL}};
	GType bala_ccode_modifiers_type_id;
	bala_ccode_modifiers_type_id = g_flags_register_static ("BalaCCodeModifiers", values);
	return bala_ccode_modifiers_type_id;
}

GType
bala_ccode_modifiers_get_type (void)
{
	static volatile gsize bala_ccode_modifiers_type_id__volatile = 0;
	if (g_once_init_enter (&bala_ccode_modifiers_type_id__volatile)) {
		GType bala_ccode_modifiers_type_id;
		bala_ccode_modifiers_type_id = bala_ccode_modifiers_get_type_once ();
		g_once_init_leave (&bala_ccode_modifiers_type_id__volatile, bala_ccode_modifiers_type_id);
	}
	return bala_ccode_modifiers_type_id__volatile;
}

