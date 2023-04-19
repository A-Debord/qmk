# Build Options
#   change yes to no to disable
#
BOOTLOADER = caterina

MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

OLED_ENABLE = yes        # Enables the use of OLED displays
OLED_DRIVER = SSD1306    # Specifies the type of OLED
SPLIT_KEYBOARD = yes     # Enables split functionality
ENCODER_ENABLE = yes	 # Enables the encoders
MOUSEKEY_ENABLE = yes    # Enables mouse movements

TAP_DANCE_ENABLE = yes      # enable multitaps
COMBO_ENABLE = yes 			# enable combos (chords)
VPATH += keyboards/gboards  # using .def for combos
# DYNAMIC_MACRO_ENABLE = yes  # record/replay macros

LTO_ENABLE = yes 			# reduce exe size