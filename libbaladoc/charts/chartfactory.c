/* chartfactory.c generated by balac, the Bala compiler
 * generated from chartfactory.bala, do not modify */

/* chartfactory.bala
 *
 * Copyright (C) 2008  Florian Brosch
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
 * 	Florian Brosch <flo.brosch@gmail.com>
 */

#include <graphviz/gvc.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "baladoc.h"
#include <glib-object.h>

enum  {
	BALADOC_CHARTS_FACTORY_0_PROPERTY,
	BALADOC_CHARTS_FACTORY_NUM_PROPERTIES
};
static GParamSpec* baladoc_charts_factory_properties[BALADOC_CHARTS_FACTORY_NUM_PROPERTIES];
#define _g_free0(var) (var = (g_free (var), NULL))

static gpointer baladoc_charts_factory_parent_class = NULL;

Agnode_t* baladoc_compat_gvc_graph_create_node (Agraph_t* graph,
                                                const gchar* name);
static Agraph_t* baladoc_charts_factory_real_create_graph (BaladocChartsFactory* self,
                                                    BaladocApiNode* item);
static GVC_t* baladoc_charts_factory_real_create_context (BaladocChartsFactory* self,
                                                   Agraph_t* graph);
static Agnode_t* baladoc_charts_factory_real_create_class (BaladocChartsFactory* self,
                                                    Agraph_t* graph,
                                                    BaladocApiClass* item);
static Agnode_t* baladoc_charts_factory_real_create_struct (BaladocChartsFactory* self,
                                                     Agraph_t* graph,
                                                     BaladocApiStruct* item);
static Agnode_t* baladoc_charts_factory_real_create_interface (BaladocChartsFactory* self,
                                                        Agraph_t* graph,
                                                        BaladocApiInterface* item);
static Agnode_t* baladoc_charts_factory_real_create_enum (BaladocChartsFactory* self,
                                                   Agraph_t* graph,
                                                   BaladocApiEnum* item);
static Agnode_t* baladoc_charts_factory_real_create_delegate (BaladocChartsFactory* self,
                                                       Agraph_t* graph,
                                                       BaladocApiDelegate* item);
static Agnode_t* baladoc_charts_factory_real_create_errordomain (BaladocChartsFactory* self,
                                                          Agraph_t* graph,
                                                          BaladocApiErrorDomain* item);
static Agnode_t* baladoc_charts_factory_real_create_namespace (BaladocChartsFactory* self,
                                                        Agraph_t* graph,
                                                        BaladocApiNamespace* item);
static Agedge_t* baladoc_charts_factory_real_add_children (BaladocChartsFactory* self,
                                                    Agraph_t* graph,
                                                    Agnode_t* parent,
                                                    Agnode_t* child);
static GType baladoc_charts_factory_get_type_once (void);

Agnode_t*
baladoc_charts_factory_create_type (BaladocChartsFactory* self,
                                    Agraph_t* graph,
                                    BaladocApiNode* item)
{
	gchar* _tmp0_;
	gchar* _tmp1_;
	Agnode_t* _tmp2_;
	Agnode_t* _tmp3_;
	Agnode_t* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (graph != NULL, NULL);
	g_return_val_if_fail (item != NULL, NULL);
	_tmp0_ = baladoc_api_node_get_full_name (item);
	_tmp1_ = _tmp0_;
	_tmp2_ = baladoc_compat_gvc_graph_create_node (graph, _tmp1_);
	_tmp3_ = _tmp2_;
	_g_free0 (_tmp1_);
	result = _tmp3_;
	return result;
}

static Agraph_t*
baladoc_charts_factory_real_create_graph (BaladocChartsFactory* self,
                                          BaladocApiNode* item)
{
	g_critical ("Type `%s' does not implement abstract method `baladoc_charts_factory_create_graph'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agraph_t*
baladoc_charts_factory_create_graph (BaladocChartsFactory* self,
                                     BaladocApiNode* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_graph (self, item);
}

static GVC_t*
baladoc_charts_factory_real_create_context (BaladocChartsFactory* self,
                                            Agraph_t* graph)
{
	g_critical ("Type `%s' does not implement abstract method `baladoc_charts_factory_create_context'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

GVC_t*
baladoc_charts_factory_create_context (BaladocChartsFactory* self,
                                       Agraph_t* graph)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_context (self, graph);
}

static Agnode_t*
baladoc_charts_factory_real_create_class (BaladocChartsFactory* self,
                                          Agraph_t* graph,
                                          BaladocApiClass* item)
{
	g_critical ("Type `%s' does not implement abstract method `baladoc_charts_factory_create_class'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agnode_t*
baladoc_charts_factory_create_class (BaladocChartsFactory* self,
                                     Agraph_t* graph,
                                     BaladocApiClass* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_class (self, graph, item);
}

static Agnode_t*
baladoc_charts_factory_real_create_struct (BaladocChartsFactory* self,
                                           Agraph_t* graph,
                                           BaladocApiStruct* item)
{
	g_critical ("Type `%s' does not implement abstract method `baladoc_charts_factory_create_struct'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agnode_t*
baladoc_charts_factory_create_struct (BaladocChartsFactory* self,
                                      Agraph_t* graph,
                                      BaladocApiStruct* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_struct (self, graph, item);
}

static Agnode_t*
baladoc_charts_factory_real_create_interface (BaladocChartsFactory* self,
                                              Agraph_t* graph,
                                              BaladocApiInterface* item)
{
	g_critical ("Type `%s' does not implement abstract method `baladoc_charts_factory_create_interface'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agnode_t*
baladoc_charts_factory_create_interface (BaladocChartsFactory* self,
                                         Agraph_t* graph,
                                         BaladocApiInterface* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_interface (self, graph, item);
}

static Agnode_t*
baladoc_charts_factory_real_create_enum (BaladocChartsFactory* self,
                                         Agraph_t* graph,
                                         BaladocApiEnum* item)
{
	g_critical ("Type `%s' does not implement abstract method `baladoc_charts_factory_create_enum'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agnode_t*
baladoc_charts_factory_create_enum (BaladocChartsFactory* self,
                                    Agraph_t* graph,
                                    BaladocApiEnum* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_enum (self, graph, item);
}

static Agnode_t*
baladoc_charts_factory_real_create_delegate (BaladocChartsFactory* self,
                                             Agraph_t* graph,
                                             BaladocApiDelegate* item)
{
	g_critical ("Type `%s' does not implement abstract method `baladoc_charts_factory_create_delegate'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agnode_t*
baladoc_charts_factory_create_delegate (BaladocChartsFactory* self,
                                        Agraph_t* graph,
                                        BaladocApiDelegate* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_delegate (self, graph, item);
}

static Agnode_t*
baladoc_charts_factory_real_create_errordomain (BaladocChartsFactory* self,
                                                Agraph_t* graph,
                                                BaladocApiErrorDomain* item)
{
	g_critical ("Type `%s' does not implement abstract method `baladoc_charts_factory_create_errordomain'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agnode_t*
baladoc_charts_factory_create_errordomain (BaladocChartsFactory* self,
                                           Agraph_t* graph,
                                           BaladocApiErrorDomain* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_errordomain (self, graph, item);
}

static Agnode_t*
baladoc_charts_factory_real_create_namespace (BaladocChartsFactory* self,
                                              Agraph_t* graph,
                                              BaladocApiNamespace* item)
{
	g_critical ("Type `%s' does not implement abstract method `baladoc_charts_factory_create_namespace'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agnode_t*
baladoc_charts_factory_create_namespace (BaladocChartsFactory* self,
                                         Agraph_t* graph,
                                         BaladocApiNamespace* item)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_CHARTS_FACTORY_GET_CLASS (self)->create_namespace (self, graph, item);
}

static Agedge_t*
baladoc_charts_factory_real_add_children (BaladocChartsFactory* self,
                                          Agraph_t* graph,
                                          Agnode_t* parent,
                                          Agnode_t* child)
{
	g_critical ("Type `%s' does not implement abstract method `baladoc_charts_factory_add_children'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return NULL;
}

Agedge_t*
baladoc_charts_factory_add_children (BaladocChartsFactory* self,
                                     Agraph_t* graph,
                                     Agnode_t* parent,
                                     Agnode_t* child)
{
	g_return_val_if_fail (self != NULL, NULL);
	return BALADOC_CHARTS_FACTORY_GET_CLASS (self)->add_children (self, graph, parent, child);
}

BaladocChartsFactory*
baladoc_charts_factory_construct (GType object_type)
{
	BaladocChartsFactory * self = NULL;
	self = (BaladocChartsFactory*) g_object_new (object_type, NULL);
	return self;
}

static void
baladoc_charts_factory_class_init (BaladocChartsFactoryClass * klass,
                                   gpointer klass_data)
{
	baladoc_charts_factory_parent_class = g_type_class_peek_parent (klass);
	((BaladocChartsFactoryClass *) klass)->create_graph = (Agraph_t* (*) (BaladocChartsFactory*, BaladocApiNode*)) baladoc_charts_factory_real_create_graph;
	((BaladocChartsFactoryClass *) klass)->create_context = (GVC_t* (*) (BaladocChartsFactory*, Agraph_t*)) baladoc_charts_factory_real_create_context;
	((BaladocChartsFactoryClass *) klass)->create_class = (Agnode_t* (*) (BaladocChartsFactory*, Agraph_t*, BaladocApiClass*)) baladoc_charts_factory_real_create_class;
	((BaladocChartsFactoryClass *) klass)->create_struct = (Agnode_t* (*) (BaladocChartsFactory*, Agraph_t*, BaladocApiStruct*)) baladoc_charts_factory_real_create_struct;
	((BaladocChartsFactoryClass *) klass)->create_interface = (Agnode_t* (*) (BaladocChartsFactory*, Agraph_t*, BaladocApiInterface*)) baladoc_charts_factory_real_create_interface;
	((BaladocChartsFactoryClass *) klass)->create_enum = (Agnode_t* (*) (BaladocChartsFactory*, Agraph_t*, BaladocApiEnum*)) baladoc_charts_factory_real_create_enum;
	((BaladocChartsFactoryClass *) klass)->create_delegate = (Agnode_t* (*) (BaladocChartsFactory*, Agraph_t*, BaladocApiDelegate*)) baladoc_charts_factory_real_create_delegate;
	((BaladocChartsFactoryClass *) klass)->create_errordomain = (Agnode_t* (*) (BaladocChartsFactory*, Agraph_t*, BaladocApiErrorDomain*)) baladoc_charts_factory_real_create_errordomain;
	((BaladocChartsFactoryClass *) klass)->create_namespace = (Agnode_t* (*) (BaladocChartsFactory*, Agraph_t*, BaladocApiNamespace*)) baladoc_charts_factory_real_create_namespace;
	((BaladocChartsFactoryClass *) klass)->add_children = (Agedge_t* (*) (BaladocChartsFactory*, Agraph_t*, Agnode_t*, Agnode_t*)) baladoc_charts_factory_real_add_children;
}

static void
baladoc_charts_factory_instance_init (BaladocChartsFactory * self,
                                      gpointer klass)
{
}

static GType
baladoc_charts_factory_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (BaladocChartsFactoryClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) baladoc_charts_factory_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (BaladocChartsFactory), 0, (GInstanceInitFunc) baladoc_charts_factory_instance_init, NULL };
	GType baladoc_charts_factory_type_id;
	baladoc_charts_factory_type_id = g_type_register_static (G_TYPE_OBJECT, "BaladocChartsFactory", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
	return baladoc_charts_factory_type_id;
}

GType
baladoc_charts_factory_get_type (void)
{
	static volatile gsize baladoc_charts_factory_type_id__volatile = 0;
	if (g_once_init_enter (&baladoc_charts_factory_type_id__volatile)) {
		GType baladoc_charts_factory_type_id;
		baladoc_charts_factory_type_id = baladoc_charts_factory_get_type_once ();
		g_once_init_leave (&baladoc_charts_factory_type_id__volatile, baladoc_charts_factory_type_id);
	}
	return baladoc_charts_factory_type_id__volatile;
}

