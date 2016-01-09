#ifndef ROFI_MAIN_H
#define ROFI_MAIN_H
#include <X11/X.h>
#include <X11/Xlib.h>
#include <glib.h>
#include <string.h>
#include <stdlib.h>
#include "timings.h"
#include "keyb.h"
#include "mode.h"

/**
 * @defgroup Main Main
 * @{
 */
/**
 * Pointer to xdg cache directory.
 */
extern const char *cache_dir;

/**
 * @param msg The error message to show.
 * @param markup The error message uses pango markup.
 *
 * The error message to show.
 */
void error_dialog ( const char *msg, int markup  );

/**
 * @param sw the Mode to show.
 * @param lines An array of strings to display.
 * @param num_lines Length of the array with strings to display.
 * @param input A pointer to a string where the inputted data is placed.
 * @param prompt The prompt to show.
 * @param shift pointer to integer that is set to the state of the shift key.
 * @param mmc Menu menu match callback, used for matching user input.
 * @param mmc_data data to pass to mmc.
 * @param selected_line pointer to integer holding the selected line.
 * @param message Extra message to display.
 *
 * Main menu callback.
 *
 * @returns The command issued (see MenuReturn)
 */
MenuReturn menu ( Mode *sw, char **input, char *prompt, unsigned int *selected_line, unsigned int *next_pos, const char *message )
__attribute__ ( ( nonnull ( 1, 2, 3, 4 ) ) );

/** Reset terminal */
#define  color_reset     "\033[0m"
/** Set terminal text bold */
#define  color_bold      "\033[1m"
/** Set terminal text italic */
#define  color_italic    "\033[2m"
/** Set terminal foreground text green */
#define color_green      "\033[0;32m"

/**
 * @param msg The error message to show.
 * @param markup If the message contains pango markup.
 *
 * Create a dialog showing the msg.
 *
 * @returns EXIT_FAILURE if failed to create dialog, EXIT_SUCCESS if succesfull
 */
int show_error_message ( const char *msg, int markup );

#define ERROR_MSG( a )    a "\n"                                       \
    "If you suspect this is caused by a bug in rofi,\n"                \
    "please report the following information to rofi's github page:\n" \
    " * The generated commandline output when the error occored.\n"    \
    " * Output of -dump-xresource\n"                                   \
    " * Steps to reproduce\n"                                          \
    " * The version of rofi you are running\n\n"                       \
    " <i>https://github.com/DaveDavenport/rofi/</i>"
#define ERROR_MSG_MARKUP    TRUE
/*@}*/
#endif
