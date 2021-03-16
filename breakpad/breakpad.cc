#include "breakpad.h"
#include "exception_handler.h"

namespace google_breakpad
{
    void setupBreakpad(const std::wstring& outputDirectory)
    {
        google_breakpad::ExceptionHandler *exception_handler;
        exception_handler = new google_breakpad::ExceptionHandler(
            outputDirectory, /* minidump output directory */
            0,   /* filter */
            0,   /* minidump callback */
            0,   /* calback_context */
            google_breakpad::ExceptionHandler::HANDLER_ALL /* handler_types */
        );

        // call TerminateProcess() to prevent any further code from
        // executing once a minidump file has been written following a
        // crash.  See ticket #17814
        exception_handler->set_terminate_on_unhandled_exception(true);
    }
}