package pvallet.com.github.hello_sdl2;

import org.libsdl.app.SDLActivity;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.app.Activity;



import android.view.inputmethod.InputMethodManager;


public class HelloSDL2Activity extends SDLActivity
{
	 /**
     * This method is called by SDL before loading the native shared libraries.
     * It can be overridden to provide names of shared libraries to be loaded.
     * The default implementation returns the defaults. It never returns null.
     * An array returned by a new implementation must at least contain "SDL2".
     * Also keep in mind that the order the libraries are loaded may matter.
     *
     * @return names of shared libraries to be loaded (e.g. "SDL2", "main").
     */

     public static void hideKeyboard(Activity activity) {
         InputMethodManager imm = (InputMethodManager) activity.getSystemService(Activity.INPUT_METHOD_SERVICE);
         //Find the currently focused view, so we can grab the correct window token from it.
         View view = activity.getCurrentFocus();
         //If no view currently has focus, create a new one, just so we can grab a window token from it
         if (view == null) {
             view = new View(activity);
         }
         imm.hideSoftInputFromWindow(view.getWindowToken(), 0);
     }


         @Override
    protected String[] getLibraries() {

    //   android.os.Debug.waitForDebugger();

	 return new String[]{
                "SDL2",
                "SDL2_image",
		        "SDL2_mixer",
                "main"
        };

    }





    }

