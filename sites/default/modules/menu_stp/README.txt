$Id: README.txt,v 1.4.4.2 2009/05/27 02:17:04 rwohleb Exp $

Menu Subtree Permissions
========================

Description
-----------
This module allows you to restrict access of menu items per roles. It depends
on the drupal core menu.module - just activate both modules and edit a menu
item as usual. There will be a new fieldset that allows you to grant editing
rights to items _in_ this container to roles of your choice.

How to use it
-------------
Just activate the menu and the menu_stp modules and edit a menu item as usual
at '/admin/build/menu'. There will be an additional fieldset that allows you
to grant editing permissions to some roles.

If you don't check any roles only a user with "administer menu" permission
can edit the menu/item and the items below. This means no change to default
behaviour.

A user creating or editing a node and having been granted access to parts of
the menu will see the usual menu-editing section with a limited set of
possible parent-items.

The weight of the menu_stp fieldset on the menu-item edit form is taken from
the drupal variable 'menu_stp_item_edit_weight'.